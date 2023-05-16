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

    
  string Common_Path = "/sys/class/gpio/";
  string Export_File = Common_Path + "export"; 
  string GPIO_Directory; 
  string Direction_File;
  string Value_File;
  
  //method 
  public :
    
        GPIO(string GPIO_Number);
       //  ~GPIO(); 

        int  Set_Value(string value);
        int  Get_Value();
        int Set_Direction(string Direction);
        // Get_Direction();

        





};



GPIO::GPIO(string GPIO_Number)
{

   // export

   cout << "The Producer of this Progrma is OH SUN CHUL " << endl; 
   cout << "Let's Constructiong gpio" << GPIO_Number << endl; 

   int fd;
   GPIO_Directory = Common_Path + "gpio" + GPIO_Number +"/"; 
  

   fd = open(Export_File.c_str(),O_WRONLY | O_CLOEXEC );

   if( fd == -1 ) 
   {

    cout << "Error to Open a File" << Export_File << "...!!!" << endl; 


   }  
   else
   {
     
     int status; 
     cout << "Succeed to Open File : " << Export_File << "...!!!" << endl; 
     status = write(fd,GPIO_Number.c_str(),GPIO_Number.length());

     if(status == -1 ) 
     {

      cout << "Error to Write " << GPIO_Number << " on File " << Export_File << endl;

     }
                    
     else 
     {
        
     
        cout << "Succeed to Create " << GPIO_Directory << "...!!!" << endl; 
        close(fd);
             

     }


   }

 

}

int GPIO::Set_Direction(string Direction)
{

  
       if(Direction == "out" || Direction == "in" )
       {    
            int fd; 
            Direction_File = GPIO_Directory + "direction";
            
            cout << "You set " << " [ " << Direction << " ] " << " on " << Direction_File << "...!!!" << endl; 
            
            fd=open(Direction_File.c_str(),O_RDWR | O_CLOEXEC);

            if( fd == -1 ) 
            {

               cout << "Error to Open File : " << Direction_File << "...!!!" << endl;
               return -1; 
            
            }
            else
            {
               int status;
               cout << "Succeed to Open File : " << Direction_File << "...!!!" << endl;
               status = write(fd,Direction.c_str(),strlen(Direction.c_str())); 
               if(status == -1 ) 
               {
                  cout << "Error to Write " << Direction << " On File " << Direction_File << "...!!!" << endl; 
                  return -1;

               }
               else 
               {

                 cout << "Succeed to Write " << " [ " << Direction << " ] " <<  " On File " << Direction_File << "...!!!" << endl; 
                 close(fd); 

               }
               

            }


       }
       else 
       {
            cout << "Error to Set GPIO Direction" << endl; 
            cout << "Direction has to be either out or in" << endl;
            return -1; 


       }
    

}


int GPIO::Set_Value(string value)
{
     
     int fd; 
     Value_File = GPIO_Directory + "value";
    

     if( value == "0" || value == "1")
     {
           
         fd = open(Value_File.c_str(),O_RDWR | O_CLOEXEC);
         if( fd == -1) 
         {

            cout << "Error to Open File " << Value_File << "...!!!" <<endl;
            return -1; 

         }
         else
         {



         }


     }
     else
     {




     }


}







int main( int argc, char* argv[])
{
   
   cout << "Hello World...!!!"<< endl;
   cout << "Author : OH SUN CHUL" << endl;
   cout << "E-mail : ispo3695@google.com" << endl;
   cout << "E-mail : ispo3695@naver.com" << endl; 
   
   
    GPIO gpio = GPIO(argv[1]); 
    gpio.Set_Direction(argv[2]);
    gpio.Set_Value(argv[3]); 

    


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