#include "mockos/CommandPrompt.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/TouchCommand.h"

int main(){
    SimpleFileSystem * sfs = new SimpleFileSystem();
    SimpleFileFactory * sff = new SimpleFileFactory();
    TouchCommand * tc = new TouchCommand(sfs, sff);
    CommandPrompt cp = CommandPrompt();
    cp.setFileFactory(sff);
    cp.setFileSystem(sfs);
    cp.addCommand("touch", tc);
    cp.run();
    return 0;
}