#include "color_transfer/color_transfer.hpp"


/*!
	\ingroup color_transfer
	\brief Вариант реализации алгоритма без логов. 
	\param[in] target изображение, к которому применяется алгоритм.
	\param[in] source исходное изображение
	\param[in] result изображение, результат работы алгоритма.
*/
void ColorTransfer(const cv::Mat& source, const cv::Mat& target, cv::Mat& result) {

	cv::Mat src, trg;
	
	cv::Mat mean_src_channels, stddev_src_channels;
	cv::Mat mean_trg_channels, stddev_trg_channels;

	cv::cvtColor(source, src, cv::COLOR_BGR2Lab);
	cv::cvtColor(target, trg, cv::COLOR_BGR2Lab);

	trg.convertTo(trg, CV_32F); 
	src.convertTo(src, CV_32F);

	cv::meanStdDev(trg, mean_trg_channels, stddev_trg_channels);
	cv::meanStdDev(src, mean_src_channels, stddev_src_channels);
	
	const double* stddev_src_channels_ptr = stddev_src_channels.ptr<double>();

	stddev_trg_channels.forEach<double>([stddev_src_channels_ptr](double& avg_val, const int* position) -> void {
		avg_val /= stddev_src_channels_ptr[*position];
	});

	stddev_src_channels_ptr = nullptr;

	const double* stddev_trg_channels_ptr = stddev_trg_channels.ptr<double>();

	const double* mean_src_channels_ptr = mean_src_channels.ptr<double>(); 

	const double* mean_trg_channels_ptr = mean_trg_channels.ptr<double>();  

	trg.forEach<Pixel>([stddev_trg_channels_ptr, mean_src_channels_ptr, mean_trg_channels_ptr]
	(Pixel& pixel, const int* position) -> void {
	
		pixel.x -= mean_trg_channels_ptr[0];
		pixel.y -= mean_trg_channels_ptr[1];
		pixel.z -= mean_trg_channels_ptr[2];

		pixel.x = pixel.x * stddev_trg_channels_ptr[0] + mean_src_channels_ptr[0];
		pixel.y = pixel.y * stddev_trg_channels_ptr[1] + mean_src_channels_ptr[1];
		pixel.z = pixel.z * stddev_trg_channels_ptr[2] + mean_src_channels_ptr[2];

	});

	trg.convertTo(trg, CV_8U);

	cv::cvtColor(trg, result, cv::COLOR_Lab2BGR);

}

/*!
	\ingroup color_transfer
	\brief Вариант реализации алгоритма с сохранением изображений, полученных на каждом этапе работы алгоритма. 
	\param[in] target изображение, к которому применяется алгоритм.
	\param[in] source исходное изображение
	\param[in] path_to_folder путь к каталогу (в случае, если каталог не существует - он будет создан) в котором будут сохранены изображения.
*/
void VerboseColorTransfer(const cv::Mat& source, const cv::Mat& target, const std::string& path_to_folder) {

	cv::imwrite(path_to_folder + "/0_source.jpg", source);
	cv::imwrite(path_to_folder + "/0_target.jpg", target);

	cv::Mat src, trg;
	
	cv::Mat mean_src_channels, stddev_src_channels;
	cv::Mat mean_trg_channels, stddev_trg_channels;

	cv::cvtColor(source, src, cv::COLOR_BGR2Lab);
	cv::cvtColor(target, trg, cv::COLOR_BGR2Lab);
	
	cv::imwrite(path_to_folder + "/1_source_Lab.jpg", src);
	cv::imwrite(path_to_folder + "/1_target_Lab.jpg", trg);
	
	trg.convertTo(trg, CV_32F);
	src.convertTo(src, CV_32F);

	cv::meanStdDev(trg, mean_trg_channels, stddev_trg_channels);
	cv::meanStdDev(src, mean_src_channels, stddev_src_channels);
	
	const double* stddev_src_channels_ptr = stddev_src_channels.ptr<double>();

	stddev_trg_channels.forEach<double>([stddev_src_channels_ptr](double& avg_val, const int* position) -> void {
		avg_val /= stddev_src_channels_ptr[*position];
	});

	stddev_src_channels_ptr = nullptr;

	const double* stddev_trg_channels_ptr = stddev_trg_channels.ptr<double>();

	const double* mean_src_channels_ptr = mean_src_channels.ptr<double>(); 

	const double* mean_trg_channels_ptr = mean_trg_channels.ptr<double>();  

	trg.forEach<Pixel>([stddev_trg_channels_ptr, mean_src_channels_ptr, mean_trg_channels_ptr]
	(Pixel& pixel, const int* position) -> void {
	
		pixel.x -= mean_trg_channels_ptr[0];
		pixel.y -= mean_trg_channels_ptr[1];
		pixel.z -= mean_trg_channels_ptr[2];

		pixel.x = pixel.x * stddev_trg_channels_ptr[0] + mean_src_channels_ptr[0];
		pixel.y = pixel.y * stddev_trg_channels_ptr[1] + mean_src_channels_ptr[1];
		pixel.z = pixel.z * stddev_trg_channels_ptr[2] + mean_src_channels_ptr[2];

	});

	cv::imwrite(path_to_folder + "/2_color_transfered_Lab.jpg", trg);

	trg.convertTo(trg, CV_8U);

	cv::cvtColor(trg, trg, cv::COLOR_Lab2BGR);

	cv::imwrite(path_to_folder + "/3_result.jpg", trg);

}