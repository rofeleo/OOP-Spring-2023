#include <iostream>
#include <vector>

namespace geo2d {
    namespace orto {
        
        class Quad {  
            
        public:
            Quad(const std::vector<std::pair<int, int>>& points);
            ~Quad() = default;
            Quad(const Quad& other) = default;
            Quad& operator=(const Quad& other);
            
        private:
            std::vector<std::pair<int, int>> points_;
            
        protected:
            void Intersect();
            void Scale(const int k);
            Quad Union(const Quad& lhs, const Quad& rhs);
        };
        
        class Square : public Quad {
            
            public:
                Square(const std::vector<std::pair<int, int>>& points) : Quad(points) {};
                ~Square();
                Square(const Square& other) = default;
                Square& operator=(const Square& other);
            
        };
        
        class Rect : public Quad {
            public:
                Rect(const std::vector<std::pair<int, int>>& points) : Quad(points) {};
                ~Rect() = default;
                Rect(const Rect& other) = default;
                Rect& operator=(const Rect& other);
        };
        
    };
    
}

geo2d::orto::Quad::Quad(const std::vector<std::pair<int, int>>& points) {
    points_ = points;
}


int main() {
    std::cout << 5;

    return 0;
}