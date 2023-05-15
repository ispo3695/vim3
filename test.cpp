#include <iostream>
#include <unistd.h> // read writhe open ...
#include <string>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <fcntl.h> // read parameter.
#include <sys/ioctl.h>



using namespace std;



int test0()
{

   cout << "test0 module...!!!" << endl; 

  // test path : /test/src/gen
  // test target : /test/src/gen/text
   
  string Path = "/test/src/gen/";
  string File = "text";
  string Target = Path + File;

  cout << "Path   =  "<< Path   << endl; 
  cout << "File   =  "<< File   << endl; 
  cout << "Target = " << Target << endl; 
  
  int fd = open(Target.c_str() , O_RDWR | O_CLOEXEC);
  
  cout << "fd = " << fd << endl;
  char RxBuffer[1024];
  memset(RxBuffer,0,sizeof(RxBuffer));
  int read_status = read(fd,RxBuffer,sizeof(RxBuffer));

  cout << "RxBuffer = " << RxBuffer << endl; 
  cout << "sizeof(RxBuffer) = " << sizeof(RxBuffer) << endl;
  cout << "read_status = " << read_status << endl;
  cout << "strlen(RxBuffer) = " << strlen(RxBuffer) << endl;

  char TxBuffer[1024];
  memset(TxBuffer,0,sizeof(TxBuffer));
 int write_status = write(fd,"010-2736-3791 Name : OH SUN CHUL\n", strlen("010-2736-3791 Name : OH SUN CHUL\n"));

 close(fd); 

   



  return 0; 


}



class GPIO 
{



 //field
  private :

    
  string default_path = "/sys/class/gpio/";
  string export_file = default_path + "export"; 
  string target_directory; 
  string Direction_File;
  string Value_File;
  
  //method 
  public :
    
        GPIO(string GPIO_Number);

        void Set_Value(int value);
        int  Get_Value();
        int Set_Direction(string Direction);
        int Get_Direction();





};



GPIO::GPIO(string GPIO_Number)
{

   // export

   int fd;
   int status;

   fd = open(export_file.c_str(),O_WRONLY | O_CLOEXEC );

   if( fd == -1 ) 
   {
        cout << "Error to Open a File" << export_file << "....!!!!" << endl; 
        cout << "Quit the Program" << endl; 
        exit(0);

   }

   else
   {
     
     cout << "파일을 여는데 성공하였습니다 ---> " << export_file << "...!!!" << endl; 
     status = write(fd,GPIO_Number.c_str(),GPIO_Number.length());

     if(status == -1 )
     {

        cout << export_file << "에 " << GPIO_Number << "를 쓰는데 실패하였습니다." << endl;
        close(fd);
        exit(0);


     }
     else 
     {
        
        target_directory = default_path + "gpio" + GPIO_Number +"/"; 
        cout << export_file << "에 " << GPIO_Number << "를 쓰는데 성공하였습니다." << endl;
        cout << target_directory << "가 생성되었습니다." << endl; 

     }


   }

 

}

int GPIO::Set_Direction(string Direction)
{


       if(Direction != "out" || Direction != "in")
       {
        cout << "방향은 out또는 in여야합니다." << endl; 
        return -1;
       }
       else 
       {    
            int fd; 
            Direction_File = target_directory + "direction";
            fd=open(Direction_File.c_str(),O_RDWR | O_CLOEXEC);




       }

  

       



}





int main( int argc, char* argv[])
{
   
   cout << "Hello World...!!!"<< endl;
   cout << "Author : OH SUN CHUL" << endl;
   cout << "E-mail : ispo3695@google.com" << endl;
   cout << "E-mail : ispo3695@naver.com" << endl; 

   GPIO gpio = GPIO(argv[1]);


  // test0();


   // cout << "argc : " << argc << endl;
   // for ( int var = 0 ; var < argc ; var++) cout << "argv[" << var << "] = " << argv[var] << endl;
    

  // path   : /sys/class/gpio 
  // target : /sys/class/gpio/export
  // target : /sys/class/gpio/unexport
  // target : /sys/class/gpio/gpio000/direction
  // target : /sys/class/gpio/gpio000/value
  
  /*
  string Common_Path = "/sys/class/gpio/";
  string Export_File = "export";
  string Target = Path + File;
  string 
  

  cout << "Path   =  " << Common_Path   << endl; 
  cout << "File   =  " << Export_File   << endl; 
  cout << "Target =  " << Export_File << endl; 
  
  int fd = open(Export_File.c_str() , O_WRONLY | O_CLOEXEC);
  cout << "fd : " << fd << endl;
  if ( fd == -1 ) cout << "Error to Open a File : " << Target << endl;
  else cout << "Succeed to Open File : " << Target << endl; 


  int write_status= write(fd,"461",strlen("461"));
  cout << "write_status : " << write_status << endl; 
  if ( write_status == -1 ) cout << "Error to Write a File : " << Target << endl;
  else cout << "Succeed to Write a File : " << Target << endl;
 */ 
   
   

  

   


  


       


   




    return 0; 

}