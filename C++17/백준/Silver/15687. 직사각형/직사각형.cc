class Rectangle {
private:
    int width, height;
public:
    Rectangle(int w, int h) {
        set_width(w);
        set_height(h);
    } 
    int get_width() const {
        return width;
    }
    int get_height() const {
        return height;
    }
    void set_width(int w) {
        if (0 < w && w<= 1000)
            width = w;
    }
    void set_height(int h) {
        if (0 < h && h <= 2000)
            height = h;
    }
    int area() const {
        return width * height;
    }
    int perimeter() const {
        return 2 * (width + height);
    }
    bool is_square() const {
        return width == height;
    }
};
