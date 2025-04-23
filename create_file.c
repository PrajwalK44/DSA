//create file
//modify file
//delete file

//create delete directory

//display contenets of file

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>

//create file 

int main(){
    //create file
    int fd = open("file_create.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if(fd == -1){
        perror("Error creating file");
    }

    int fd = open("file_create.txt", O_WRONLY);

    //write into file
    write(fd, "Hello to the world!!", 20);

    //modify the contents
    int fd = open("file_create.txt", O_WRONLY | O_APPEND);
    if(fd == -1){
        perror("Error creating file");
    }
    write(fd, "New content", 11);

    if(mkdir("new_dir")==-1){
        perror("Error creating directory");
    }

    // delete the file
    if(unlink("file_create.txt")==-1){
        perror("Error deleting file");
    }

    //delete directory
    if(rmdir("new_dir")==-1){
        perror("Error deleting directory");
    }

    //display the contents of file

    //read
    int fd = open("file_create.txt", O_RDONLY);
    char buffer[1024];
    ssize_t bytesRead;
    while((bytesRead = read(fd, buffer, sizeof(buffer)) )>0){
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    return 0;
}