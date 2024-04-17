#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"

AbstractFileSystem* afs = new SimpleFileSystem();
AbstractFileFactory* aff = new SimpleFileFactory();

(*aff).createFile("hi");