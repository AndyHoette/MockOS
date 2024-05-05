#pragma once
class TextFile;//Forward Declaration
class ImageFile;//Forward Declaration
//Way to visit a file to print out files of different types
class AbstractFileVisitor{
public:
    virtual void visit_TextFile(TextFile* file) = 0; //visits a text file
    virtual void visit_ImageFile(ImageFile* file) = 0;//visits an image file
};