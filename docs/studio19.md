# Studio 19

2. We created an ImageFile called a, then updated the contents using a local vector of chars 
called contents. We then wrote the image file taking in the parameter contents. Then we printed called 
read again which returned a new vector of chars and we printed out the new vector of chars to make sure 
the read() and write() functions were working. 
3. The visitor is called through the accept method and can access the element within the this pointer 
it is used to remove clutter of adding multiple methods for different file types. The visitor can access 
the object and modify it. 
4. Each class just needs to have an accept function that allows the visitor to interact with the class. 
The process of actually doing the task is delegated to the visitor class and the actual imagefile or textfile
doesn't need to know how its done. 
5. If we had a lot of visitors and then added a new file type, it would take quite a long time to 
go through every visitor and add a different implementation of to every visitor for the new file type. 
This can be time consuming and challenging. Sometimes its just easier to implement the method within the 
concrete class and not use a visitor. 