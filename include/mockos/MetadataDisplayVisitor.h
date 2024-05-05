#pragma once
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"
//Visitor to display the metadata of the files
class MetadataDisplayVisitor : public AbstractFileVisitor{
    void visit_TextFile(TextFile* file) override;//for text file
    void visit_ImageFile(ImageFile* file) override;//for image file
};
