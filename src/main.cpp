#include<iostream>
#include<thread>
#include<chrono>
#include<sys/types.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

void manejador(int signum){
  switch(signum){
    case SIGUSR1:
      exit(EXIT_SUCCESS);
      break;
    case SIGUSR2:
      exit(EXIT_SUCCESS);
      break;
    case SIGINT:
      cout<<"Detencion no permitida"<<endl;
      break;
    case SIGQUIT:
      cout<<"Detencion no permitida"<<endl;
      break;
    case SIGTSTP:
      cout<<"Detencion no permitida"<<endl;
      break;
    default:
      break;
  }
}
int main(){
  int pid;
  int c=1;
  long long int fibo3=0,fibo2=0,fibo1=1;
  pid=fork();
  signal(SIGUSR1,manejador);
  signal(SIGUSR2,manejador);
  signal(SIGINT,manejador);
  signal(SIGQUIT,manejador);
  signal(SIGTSTP,manejador);
  for(int i=0;i<50;i++){
    if(pid==0){
      std::this_thread::sleep_for(std::chrono::seconds(1));
      cout<<"Valor impar: "<<c<<" - PID = "<<getpid()<<endl;
      c=c+2;
    }
    else if(pid>0)
    {
      fibo3=fibo2 + fibo1;
      fibo2=fibo1;
      fibo1=fibo3;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      cout<<"Valor de Fibonacci: "<<fibo3<<" - PPIDE = "<<getpid()<<endl;
    }
  }
}
