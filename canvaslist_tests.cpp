#include <gtest/gtest.h>

#include "canvaslist.h"
#include "shape.h"

//
// Shape Class tests
//
TEST(ShapeConstructors, Default) {
    Shape test;

    EXPECT_EQ(0, test.getX()) << "test x is not 0\n";
    EXPECT_EQ(0, test.getY()) << "test y is not 0\n";
}

TEST(ShapeConstructors, Parameterized) {
    Shape test(1, 2);
    
    EXPECT_EQ(1, test.getX()) << "test x is not 1\n";
    EXPECT_EQ(2, test.getY()) << "test y is not 2\n";
}

TEST(ShapeCopy, Copying) {
    Shape base(11, 11);

    Shape* test = base.copy();

    EXPECT_EQ(11, test->getX()) << "test x is not 11\n";
    EXPECT_EQ(11, test->getY()) << "test y is not 11\n";

    delete test;
}

TEST(ShapeSetters, Set) {
    Shape test;

    test.setX(123);
    test.setY(2);

    EXPECT_EQ(123, test.getX()) << "test x is not 123\n";
    EXPECT_EQ(2, test.getY()) << "test y is not 2\n";
}

TEST(ShapeAsString, AsString) {
    Shape test(3, 5);

    string s = test.as_string();

    EXPECT_EQ("It's a Shape at x: 3, y: 5", s) << "strings are not equal\n";
}

//
// Circle Class Tests
//
TEST(CircleConstructors, Default) {
    Circle test;

    EXPECT_EQ(0, test.getX()) << "x is not 0\n";
    EXPECT_EQ(0, test.getY()) << "y is not 0\n";
    EXPECT_EQ(0, test.getRadius()) << "radius is not 0\n";
}

TEST(CircleConstructors, RadiusOnly) {
    Circle test(4);

    EXPECT_EQ(0, test.getX()) << "x is not 0\n";
    EXPECT_EQ(0, test.getY()) << "y is not 0\n";
    EXPECT_EQ(4, test.getRadius()) << "radius is not 4\n";
}

TEST(CircleConstructors, FullParameters) {
    Circle test(1, 2, 4);

    EXPECT_EQ(1, test.getX()) << "x is not 1\n";
    EXPECT_EQ(2, test.getY()) << "y is not 2\n";
    EXPECT_EQ(4, test.getRadius()) << "radius is not 4\n";
}

TEST(CircleCopy, Copy) {
    Circle base(2, 6, 19);

    Circle* test = base.copy();

    EXPECT_EQ(2, test->getX()) << "test x is not 2\n";
    EXPECT_EQ(6, test->getY()) << "test y is not 6\n";
    EXPECT_EQ(19, test->getRadius()) << "test radius is not 19\n";

    delete test;
}

TEST(CircleSetters, Setters) {
    Circle test;

    test.setX(153);
    test.setY(542);
    test.setRadius(674);

    EXPECT_EQ(153, test.getX()) << "x is not 153\n";
    EXPECT_EQ(542, test.getY()) << "y is not 542\n";
    EXPECT_EQ(674, test.getRadius()) << "radius is not 674\n";
}

TEST(CircleAsString, AsString) {
    Circle test(15, 16, 17);

    string s = test.as_string();

    EXPECT_EQ("It's a Circle at x: 15, y: 16, radius: 17", s) << "strings are not equal\n";
}

//
// Rect tests
//
TEST(RectConstructors, Default) {
    Rect test;

    EXPECT_EQ(0, test.getX()) << "x is not 0\n";
    EXPECT_EQ(0, test.getY()) << "y is not 0\n";
    EXPECT_EQ(0, test.getWidth()) << "width is not 0\n";
    EXPECT_EQ(0, test.getHeight()) << "height is not 0\n";
}

TEST(RectConstructors, HeightWidthOnly) {
    Rect test(4, 5);

    EXPECT_EQ(0, test.getX()) << "x is not 0\n";
    EXPECT_EQ(0, test.getY()) << "y is not 0\n";
    EXPECT_EQ(4, test.getWidth()) << "width is not 4\n";
    EXPECT_EQ(5, test.getHeight()) << "height is not 5\n";
}

TEST(RectConstructors, AllParameters) {
    Rect test(18, 19, 20, 21);

    EXPECT_EQ(18, test.getX()) << "x is not 18\n";
    EXPECT_EQ(19, test.getY()) << "y is not 19\n";
    EXPECT_EQ(20, test.getWidth()) << "width is not 20\n";
    EXPECT_EQ(21, test.getHeight()) << "height is not 21\n";
}

TEST(RectCopy, Copy) {
    Rect base(9, 8, 7, 6);

    Rect* test = base.copy();

    EXPECT_EQ(9, test->getX()) << "x is not 9\n";
    EXPECT_EQ(8, test->getY()) << "y is not 8\n";
    EXPECT_EQ(7, test->getWidth()) << "width is not 7\n";
    EXPECT_EQ(6, test->getHeight()) << "height is not 6\n";

    delete test;
}

TEST(RectSetters, Set) {
    Rect test;

    test.setX(14);
    test.setY(33);
    test.setHeight(44);
    test.setWidth(55);

    EXPECT_EQ(14, test.getX()) << "x is not 14\n";
    EXPECT_EQ(33, test.getY()) << "y is not 33\n";
    EXPECT_EQ(55, test.getWidth()) << "width is not 44\n";
    EXPECT_EQ(44, test.getHeight()) << "height is not 55\n";
}

TEST(RectAsString, AsString) {
    Rect test(1, 1, 1, 1);

    string s = test.as_string();

    EXPECT_EQ("It's a Rectangle at x: 1, y: 1 with width: 1 and height: 1", s) << "strings aren't equal\n";
}

//
// RightTriangle tests
//
TEST(RightTriangleConstructors, Default) {
    RightTriangle test;

    EXPECT_EQ(0, test.getX()) << "x not 0\n";
    EXPECT_EQ(0, test.getY()) << "y no 0\n";
    EXPECT_EQ(0, test.getBase()) << "base not 0\n";
    EXPECT_EQ(0, test.getHeight()) << "height not 0\n";
}

TEST(RightTriangleConstructors, BaseHeight) {
    RightTriangle test(5, 9);

    EXPECT_EQ(0, test.getX()) << "x not 0\n";
    EXPECT_EQ(0, test.getY()) << "y no 0\n";
    EXPECT_EQ(5, test.getBase()) << "base not 5\n";
    EXPECT_EQ(9, test.getHeight()) << "height not 9\n";
}

TEST(RightTriangleConstructors, AllParameters) {
    RightTriangle test(1,2,3,4);

    EXPECT_EQ(1, test.getX()) << "x not 1\n";
    EXPECT_EQ(2, test.getY()) << "y no 2\n";
    EXPECT_EQ(3, test.getBase()) << "base not 3\n";
    EXPECT_EQ(4, test.getHeight()) << "height not 4\n";
}

TEST(RightTriangleCopy, Copy) {
    RightTriangle base(2,8,16,32);

    RightTriangle* test = base.copy();

    EXPECT_EQ(2, test->getX()) << "x not 2\n";
    EXPECT_EQ(8, test->getY()) << "y no 8\n";
    EXPECT_EQ(16, test->getBase()) << "base not 16\n";
    EXPECT_EQ(32, test->getHeight()) << "height not 32\n";

    delete test;
}

TEST(RightTriangleSet, Set) {
    RightTriangle test;

    test.setX(15);
    test.setY(30);
    test.setBase(45);
    test.setHeight(60);

    EXPECT_EQ(15, test.getX()) << "x not 15\n";
    EXPECT_EQ(30, test.getY()) << "y no 30\n";
    EXPECT_EQ(45, test.getBase()) << "base not 45\n";
    EXPECT_EQ(60, test.getHeight()) << "height not 60\n";
}

TEST(RightTriangleAsString, AsString) {
    RightTriangle test(1, 3, 4, 100);

    string s = test.as_string();

    EXPECT_EQ("It's a Right Triangle at x: 1, y: 3 with base: 4 and height: 100", s) << "strings aren't equal\n";
}

//
//default constructor test
//
TEST(DefaultConstructor, Constructor) {
    CanvasList test;

    EXPECT_EQ(0, test.size()) << "Default CanvasList size is not 0.\n";
    EXPECT_EQ(nullptr, test.front()) << "Default CanvasList front is not nullptr.\n";
}

//
//copy constructor test
//
TEST(CopyConstructor, Constructor) {
    CanvasList base;

    Shape* s1 = new Shape(1, 2);
    Shape* s2 = new Shape(3, 4);
    Shape* s3 = new Shape(5, 6);

    base.push_front(s1);
    base.push_front(s2);
    base.push_front(s3);

    CanvasList test(base);

    ASSERT_NE(base.front(), test.front()) << "Addresses of head nodes are the same, shallow copy\n";
    EXPECT_EQ(base.front()->value->as_string(), 
              test.front()->value->as_string()) << "Values of the shapes at the head nodes are not the same\n";
    EXPECT_EQ(base.front()->next->value->as_string(), 
              test.front()->next->value->as_string()) << "Values of the shapes at index 1 are not the same\n";
    EXPECT_EQ(base.front()->next->next->value->as_string(), 
              test.front()->next->next->value->as_string()) << "Values of the shapes at index 2 are not the same\n";
    EXPECT_EQ(base.size(), test.size()) << "Size of lists are not the same\n";
}


TEST(CopyConstructor, EmptyCopy) {
    CanvasList base;
    CanvasList test(base);

    EXPECT_EQ(nullptr, test.front()) << "test.front() is not nullptr\n";
    EXPECT_EQ(base.front(), test.front()) << "test and base are not both nullptr\n";
}

//
// operator= tests
//
TEST(CopyOperator, Constructor) {
    CanvasList base;

    Shape* s1 = new Shape(1, 2);
    Shape* s2 = new Shape(3, 4);
    Shape* s3 = new Shape(5, 6);

    base.push_front(s1);
    base.push_front(s2);
    base.push_front(s3);

    CanvasList test = base;

    ASSERT_NE(base.front(), test.front()) << "Addresses of head nodes are the same, shallow copy\n";
    EXPECT_EQ(base.front()->value->as_string(), 
              test.front()->value->as_string()) << "Values of the shapes at the head nodes are not the same\n";
    EXPECT_EQ(base.front()->next->value->as_string(), 
              test.front()->next->value->as_string()) << "Values of the shapes at index 1 are not the same\n";
    EXPECT_EQ(base.front()->next->next->value->as_string(), 
              test.front()->next->next->value->as_string()) << "Values of the shapes at index 2 are not the same\n";
    EXPECT_EQ(base.size(), test.size()) << "Size of lists are not the same\n";
}


TEST(CopyOperator, EmptyCopy) {
    CanvasList base;
    CanvasList test = base;

    EXPECT_EQ(nullptr, test.front()) << "test.front() is not nullptr\n";
    EXPECT_EQ(base.front(), test.front()) << "test and base are not both nullptr\n";
}

TEST(CopyOperator, CopyingEmptyOnFilled) {
    CanvasList base;
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;

    test.push_back(s1);
    test.push_back(s2);

    test = base;

    EXPECT_EQ(nullptr, test.front()) << "test.front() is not nullptr\n";
    EXPECT_EQ(base.front(), test.front()) << "base and test are not both nullptr\n";
    EXPECT_EQ(0, test.size()) << "test size is not 0\n";
}

TEST(CopyOperator, CopyFilledOnFilled) {
    CanvasList base;

    Shape* s1 = new Shape(1,1);
    Shape* s2 = new Shape(2,2);
    Shape* s3 = new Shape(3,3);

    base.push_back(s1);
    base.push_back(s2);
    base.push_back(s3);

    CanvasList test;

    Shape* s4 = new Shape(4,4);
    Shape* s5 = new Shape(5,5);
    
    test.push_back(s4);
    test.push_back(s5);

    test = base;

    EXPECT_EQ(base.front()->value->as_string(), test.front()->value->as_string()) << "test front is not s1\n";
    EXPECT_NE(base.front(), test.front()) << "test is a shallow copy\n";
    EXPECT_EQ(base.shape_at(1)->as_string(), test.shape_at(1)->as_string()) << "shape_at index 1 is not s2 in test\n";
    EXPECT_NE(base.shape_at(1), test.shape_at(1)) << "s2 is shallowly copied\n";
    ASSERT_EQ(base.size(), test.size()) << "base and test are not the same size\n";
    EXPECT_EQ(base.shape_at(2)->as_string(), test.shape_at(2)->as_string()) << "s3 is not the value at index 2 in test\n";
}

TEST(CopyOperator, SelfCopy) {
    CanvasList test;

    Shape* s = new Shape;

    test.push_back(s);

    test = test;

    ASSERT_NE(nullptr, test.front()) << "test was cleared in the self-copy\n";
    EXPECT_EQ(s, test.front()->value) << "s is not the front of test\n";
    EXPECT_EQ(1, test.size()) << "test size is not 1\n";
}
//
// clear() tests
//
TEST(Clear, ClearingNormalList) {
    CanvasList test;
    Shape* shape1 = new Shape;
    Shape* shape2 = new Shape;
    Shape* shape3 = new Shape;

    test.push_front(shape1);
    test.push_front(shape2);
    test.push_front(shape3);

    test.clear();

    EXPECT_EQ(nullptr, test.front()) << "Front is not nullptr\n";
    EXPECT_EQ(0, test.size()) << "Size is not zero\n";
}

TEST(Clear, ClearingEmptyList) {
    CanvasList test;

    //this is more or less just to see if it causes segfaults
    test.clear();

    EXPECT_EQ(nullptr, test.front()) << "Somehow, Front is not nullptr\n";
    EXPECT_EQ(0, test.size()) << "Somehow, size is not zero\n";
}

//
// insert_after() tests
//
TEST(InsertAfter, Adding) {
    CanvasList test;
    Shape* shape1 = new Shape;
    Shape* shape2 = new Shape;
    Shape* shape3 = new Shape;

    test.push_front(shape3);
    test.push_front(shape2);
    test.push_front(shape1);

    Shape* shape4 = new Shape;

    test.insert_after(1, shape4);

    EXPECT_EQ(shape4, test.shape_at(2)) << "shape4 is not at index 2\n";
    EXPECT_EQ(4, test.size()) << "list_size was not update properly\n";
    
    ShapeNode* curr = test.front();
    curr = curr->next; //node at index 1, SHOULD BE shape2
    ASSERT_EQ(shape2, curr->value) << "curr->value is NOT shape2. It needs to be\n";

    EXPECT_EQ(shape4, curr->next->value) << "shape4 is not after node at index 2\n";
    
    curr = curr->next; //curr is now at index 2, SHOULD BE shape 4
    ASSERT_EQ(shape4, curr->value) << "curr->value is NOT shape4. It needs to be\n";

    EXPECT_EQ(shape3, curr->next->value) << "shape3 is not after shape4\n";
}

TEST(InsertAfter, InvalidIndex) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;

    test.push_back(s1);

    test.insert_after(3, s2);
    test.insert_after(1, s2);
    test.insert_after(-1, s2);

    EXPECT_EQ(nullptr, test.front()->next) << "There is something after s1, there shouldn't be\n";
    test.insert_after(0, s2); //this should work

    //test passes if there's not a segmentation fault ;)
}

TEST(InsertAfter, AfterLastIndex) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;

    test.push_back(s1);
    test.push_back(s2);

    test.insert_after(1, s3);

    EXPECT_EQ(s3, test.shape_at(2)) << "s3 is not the shape at index 2\n";
    EXPECT_EQ(3, test.size()) << "size was not updated to 3\n";
}

TEST(InsertAfter, InsertingAfterInserted) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;
    Shape* s4 = new Shape;

    test.push_back(s1);
    test.push_back(s4);

    test.insert_after(0, s2);
    test.insert_after(1, s3);

    EXPECT_EQ(s3, test.shape_at(2)) << "s3 is not at index 2\n";
    EXPECT_EQ(s4, test.shape_at(3)) << "s4 is not at index 3\n";
    EXPECT_EQ(s2, test.shape_at(1)) << "s2 is not at index 1\n";
    EXPECT_EQ(s4, test.front()->next->next->next->value) << "the chain is not properly built\n";
}

//
// push_front() tests
//
TEST(PushFront, AddingToEmpty) {
    CanvasList test;
    Shape* shape = new Shape;

    test.push_front(shape);

    EXPECT_EQ(shape, test.front()->value) << "shape is not the front of test\n";
    EXPECT_EQ(nullptr, test.front()->next) << "nullptr is not next\n";
    EXPECT_EQ(1, test.size()) << "size is not 1\n";
}

TEST(PushFront, AddingToSizeOne) {
    CanvasList test;
    Shape* shape1 = new Shape;

    test.push_front(shape1);

    Shape* shape2 = new Shape;

    test.push_front(shape2);

    EXPECT_EQ(shape2, test.front()->value) << "shape2 is not the front of test\n";
    EXPECT_EQ(shape1, test.front()->next->value) << "shape1 is not considered front()->next\n";
    EXPECT_EQ(2, test.size()) << "size is not 2\n";
}

//
// push_back() tests
//
TEST(PushBack, AddingToEmpty) {
    CanvasList test;
    Shape* shape = new Shape;

    test.push_back(shape);

    EXPECT_EQ(shape, test.front()->value) << "shape is not the front of test\n";
    EXPECT_EQ(nullptr, test.front()->next) << "nullptr is not next\n";
    EXPECT_EQ(1, test.size()) << "size is not 1\n";
}

TEST(PushBack, AddingToBack) {
    CanvasList test;
    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;
    Shape* s4 = new Shape;

    test.push_back(s1);
    EXPECT_EQ(s1, test.front()->value) << "s1 is not the front of test\n";
    EXPECT_EQ(1, test.size()) << "test is not size 1\n";

    test.push_back(s2);
    EXPECT_EQ(s2, test.front()->next->value) << "s2 is not front->next\n";
    EXPECT_EQ(2, test.size()) << "test is not size 2 after second push_back\n";

    test.push_back(s3);
    EXPECT_EQ(s3, test.front()->next->next->value) << "s3 is not front->next->next->value\n";
    EXPECT_EQ(3, test.size()) << "test is not size 3 after third push_back\n";

    test.push_back(s4);
    EXPECT_EQ(s4, test.front()->next->next->next->value) << "s4 is not front->next->next->next->value\n";
    EXPECT_EQ(4, test.size()) << "test is not size 4 after fourth push_back\n";
}

//
// remove_at() tests
//
TEST(RemoveAt, RemovingMiddle) {
    CanvasList test;
    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);

    test.remove_at(1); //should remove s2;

    EXPECT_NE(s2, test.shape_at(1)) << "s2 is at index 1, even though it should be removed\n";
    EXPECT_EQ(2, test.size()) << "test is not size 2\n";
    EXPECT_EQ(s3, test.front()->next->value) << "shape after front is not s3\n";
}

TEST(RemoveAt, RemovingBeginning) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);

    test.remove_at(0); //should remove s1;

    EXPECT_NE(s1, test.shape_at(0)) << "s1 is at index 0, even though it should be removed\n";
    EXPECT_EQ(2, test.size()) << "test is not size 2\n";
    EXPECT_EQ(s2, test.front()->value) << "front shape is not s2\n";
    EXPECT_EQ(s3, test.shape_at(1)) << "shape at 1 is not s3\n";
}

TEST(RemoveAt, RemovingEnd) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);

    test.remove_at(2); //should remove s3;

    EXPECT_EQ(nullptr, test.shape_at(2)) << "remove_at(2) did not return nullptr\n";
    EXPECT_EQ(2, test.size()) << "test is not size 2\n";
}

TEST(RemoveAt, InvalidIndex) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);

    test.remove_at(4); //invalid, this is a success if there's no segfaults since the list won't be updated
}

TEST(RemoveAt, RemovingFromSizeOne) {
    CanvasList test;

    Shape* s = new Shape;

    test.push_back(s);

    test.remove_at(0);

    EXPECT_EQ(0, test.size()) << "Size is not 0\n";
    EXPECT_EQ(nullptr, test.front()) << "list_front is not nullptr\n";
}

//
// remove_every_other() tests
//
TEST(RemoveEveryOther, Empty) {
    CanvasList test;

    test.remove_every_other();

    //This passes if there isn't a segmentation fault
}

TEST(RemoveEveryOther, One) {
    //expected behavior is that it leaves the single list alone
    CanvasList test;

    Shape* s = new Shape;

    test.push_back(s);

    test.remove_every_other();

    ASSERT_NE(nullptr, test.front()) << "front node was removed even though it shouldn't have been\n";
    EXPECT_EQ(s, test.front()->value) << "s is not the front of list\n";
    EXPECT_EQ(1, test.size()) << "size is not 1\n";
}

TEST(RemoveEveryOther, Two) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;

    test.push_back(s1);
    test.push_back(s2);

    test.remove_every_other();

    EXPECT_EQ(s1, test.front()->value) << "s1 is not the front of test\n";
    EXPECT_NE(s2, test.front()->value) << "s2 should not be the front of test\n";
    EXPECT_EQ(1, test.size()) << "size is not 1\n";
    EXPECT_EQ(nullptr, test.front()->next) << "node after front should be nullptr\n";
}

TEST(RemoveEveryOther, EvenNumber) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;
    Shape* s4 = new Shape;
    Shape* s5 = new Shape;
    Shape* s6 = new Shape;

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);
    test.push_back(s4);
    test.push_back(s5);
    test.push_back(s6);

    test.remove_every_other(); //list should be s1, s3, s5 after this

    EXPECT_EQ(s3, test.front()->next->value) << "Value after s1 is not s3\n";
    EXPECT_EQ(s1, test.front()->value) << "Head node value is not s1\n";
    EXPECT_EQ(s5, test.front()->next->next->value) << "Value after s3 is not s5\n";
    EXPECT_EQ(3, test.size()) << "Size of list is not 3\n";
    ASSERT_EQ(nullptr, test.front()->next->next->next) << "Value after s5 is not nullptr\n";
}

TEST(RemoveEveryOther, OddNumber) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;
    Shape* s4 = new Shape;
    Shape* s5 = new Shape;

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);
    test.push_back(s4);
    test.push_back(s5);

    test.remove_every_other(); //list should be s1, s3, s5 after this. Should be the same as even test

    EXPECT_EQ(s3, test.front()->next->value) << "Value after s1 is not s3\n";
    EXPECT_EQ(s1, test.front()->value) << "Head node value is not s1\n";
    EXPECT_EQ(s5, test.front()->next->next->value) << "Value after s3 is not s5\n";
    EXPECT_EQ(3, test.size()) << "Size of list is not 3\n";
    ASSERT_EQ(nullptr, test.front()->next->next->next) << "Value after s5 is not nullptr\n";
}

//
// pop_front() tests
//
TEST(PopFront, EmptyList) {
    CanvasList base;

    Shape* test = base.pop_front();

    EXPECT_EQ(nullptr, test) << "pop_front() did not pass for an empty CanvasList\n";
}

TEST(PopFront, ListSizeOne) {
    CanvasList base;

    Shape* triangle = new Shape;

    base.push_front(triangle);

    Shape* test = base.pop_front();

    EXPECT_EQ(triangle, test) << "pop_front() did return the correct shape\n";
    EXPECT_EQ(nullptr, base.front()) << "pop_front() did not remove the head node\n";
    EXPECT_EQ(0, base.size()) << "pop_front() did not update the list size\n";

    delete test;
}

//
// pop_back() tests
//
TEST(PopBack, NormalPop) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape;

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);

    Shape* popped = test.pop_back();

    EXPECT_EQ(s3, popped) << "s3 was not popped from the back of the list\n";
    EXPECT_EQ(2, test.size()) << "size was not updated to 2\n";

    delete popped;
}

TEST(PopBack, PopEmpty) {
    CanvasList test;

    Shape* s = test.pop_back();

    EXPECT_EQ(nullptr, s) << "nullptr was not returned on empty pop\n";
}

TEST(PopBack, PopSizeOne) {
    CanvasList test;

    Shape* s = new Shape;

    test.push_back(s);

    Shape* sp = test.pop_back();

    EXPECT_EQ(s, sp) << "you did not pop the one shape in the list\n";
    EXPECT_EQ(0, test.size()) << "size was not updated to 0\n";
    EXPECT_EQ(nullptr, test.front()) << "list_front is not nullptr\n";

    delete sp;
}

//
// find() tests
//
TEST(Find, GenericFind) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape(1, 2);
    Shape* s4 = new Shape;

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);
    test.push_back(s4);

    int foundex = test.find(1, 2);

    EXPECT_EQ(2, foundex) << "find did not return 2\n";
}

TEST(Find, NotInList) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape;
    Shape* s3 = new Shape(1, 2);
    Shape* s4 = new Shape;

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);
    test.push_back(s4);

    int foundex = test.find(2, 2);

    EXPECT_EQ(-1, foundex) << "Your test is a stupid fucking liar who says he found a shape that doesn't even exist. Are you proud to have created such an awful, terrible, anti-social test?\n";
}

TEST(Find, Empty) {
    CanvasList test;

    int foundex = test.find(0, 1);

    EXPECT_EQ(-1, foundex) << "Test found something in an empty list without causing a segfault, somehow\n";
}

TEST(Find, One) {
    CanvasList test;

    Shape* s = new Shape(1, 4);

    test.push_back(s);

    int foundex = test.find(1, 4);

    EXPECT_EQ(0, foundex) << "Test did not return 0 as index\n";
}

TEST(Find, DuplicatesInList) {
    CanvasList test;

    Shape* s1 = new Shape;
    Shape* s2 = new Shape(1, 1);
    Shape* s3 = new Shape;
    Shape* s4 = new Shape(1, 1);

    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);
    test.push_back(s4);

    int foundex = test.find(1, 1);

    EXPECT_EQ(1, foundex) << "Test did not return 1 as index\n";
    EXPECT_NE(3, foundex) << "Index 3 should not be returned since it is later than earlier duplicate shape\n";
}