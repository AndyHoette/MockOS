#pragma once
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
//This method displays the image and text files
class BasicDisplayVisitor : public AbstractFileVisitor{
public:
    void visit_TextFile(TextFile* file) override;//Takes in a textFile to display
    void visit_ImageFile(ImageFile* file) override;//Takes in an imageFile to display
};