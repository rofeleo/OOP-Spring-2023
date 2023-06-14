#include "color_transfer/color_transfer.hpp"

#include <boost/program_options.hpp>

#include <string>

/*! 
  \defgroup test_app Тестовое приложение 
  \brief Тестовое приложение для взаимодействия с пользователем через командную строку и вызова алгоритма преобразования цвета
  Здесь реализована обработка введенных пользователем параметров командной строки, выбор алгоритма 
  в соответсвии с параметрами, создание каталога для сохранения файлов, в случае необходимости.
*/

namespace po = boost::program_options;

/*!
  \ingroup test_app
*/
int main(int argc, char* argv[]) {
  std::string path_to_target, path_to_source, path_to_result;

  bool visualize(0);
  po::options_description description("Allowed options");
  auto&& options = description.add_options();
  options("help,h", "show available options");
  options("vis,v", po::value<std::string>(&path_to_result), "flag for visualization (needs path to save result)");
  options("src,s", po::value<std::string>(&path_to_source), "source image");
  options("tgt,t", po::value<std::string>(&path_to_target), "target image");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, description), vm);
  po::notify(vm);

  if (vm.count("help") || !vm.count("src") || !vm.count("tgt")) {
    std::cout << description << std::endl;
    return 1;
  }

  cv::Mat image = cv::imread(path_to_source);
  cv::Mat image2 = cv::imread(path_to_target);

  if (vm.count("vis")) {
    if (!std::filesystem::exists(path_to_result)) {
      if (!std::filesystem::create_directories(path_to_result)) {
        std::cout << "Failed to create folder - aborting..." << std::endl;
        return -1;
      }
    }
    VerboseColorTransfer(image, image2, path_to_result);
  } else {
    cv::Mat result; 
    ColorTransfer(image, image2, result);
    
    cv::imshow("Result", result);
    cv::waitKey(0);
  }
  
  return 0;
}
