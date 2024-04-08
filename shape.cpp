#include "shape.h"

#include <string>

using namespace std;

Shape::Shape() {
    x = 0;
    y = 0;
}

Shape::Shape(int x, int y) {
    this->x = x;
    this->y = y;
}

Shape::~Shape() {
    //no extra instruction needed
}

Shape* Shape::copy() {
    Shape* copyShape = new Shape;

    copyShape->setX(x);
    copyShape->setY(y);
    
    return copyShape;
}

int Shape::getX() const {
    return x;
}

int Shape::getY() const {
    return y;
}

void Shape::setX(int x) {
    this->x = x;
}

void Shape::setY(int y) {
    this->y = y;
}

string Shape::as_string() const {
    return "It's a Shape at x: " + to_string(x) + ", y: " + to_string(y);
}

Circle::Circle() {
    x = 0;
    y = 0;
    radius = 0;
}

Circle::Circle(int r) {
    x = 0;
    y = 0;
    radius = r;
}

Circle::Circle(int x, int y, int r) {
    this->x = x;
    this->y = y;
    radius = r;
}

Circle::~Circle() {
    //no extra instruction needed
}

Circle* Circle::copy() {
    Circle* c = new Circle(x, y, radius);
    return c;
}

int Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(int r) {
    radius = r;
}

string Circle::as_string() const {
    return "It's a Circle at x: " + to_string(x) + ", y: " + to_string(y) + ", radius: " + to_string(radius);
}

Rect::Rect() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

Rect::Rect(int w, int h) {
    x = 0;
    y = 0;
    width = w;
    height = h;
}

Rect::Rect(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    width = w;
    height = h;
}

Rect::~Rect() {
    //no further instruction needed
}

Rect* Rect::copy() {
    Rect* r = new Rect(x, y, width, height);
    return r;
}

int Rect::getWidth() const {
    return width;
}

int Rect::getHeight() const {
    return height;
}

void Rect::setWidth(int w) {
    width = w;
}

void Rect::setHeight(int h) {
    height = h;
}

string Rect::as_string() const {
    return "It's a Rectangle at x: " + to_string(x) + ", y: " + to_string(y) +
           " with width: " + to_string(width) + " and height: " + to_string(height);
}

RightTriangle::RightTriangle() {
    x = 0;
    y = 0;
    base = 0;
    height = 0;
}

RightTriangle::RightTriangle(int b, int h) {
    x = 0;
    y = 0;
    base = b;
    height = h;
}

RightTriangle::RightTriangle(int x, int y, int b, int h) {
    this->x = x;
    this->y = y;
    base = b;
    height = h;
}

RightTriangle::~RightTriangle() {
    //no further instruction needed
}

RightTriangle* RightTriangle::copy() {
    RightTriangle* rt = new RightTriangle(x, y, base, height);
    return rt;
}

int RightTriangle::getBase() const {
    return base;
}

int RightTriangle::getHeight() const {
    return height;
}

void RightTriangle::setBase(int b) {
    base = b;
}

void RightTriangle::setHeight(int h) {
    height = h;
}

string RightTriangle::as_string() const {
    return "It's a Right Triangle at x: " + to_string(x) + ", y: " + to_string(y) +
           " with base: " + to_string(base) + " and height: " + to_string(height);
}