#include "../mystl/memory"
#include <iostream>
#include <vector>
#include <list>
int main ()
{

    // numb::allocator<int> alloc;
    // numb::allocator<int>& address_alloc = alloc;

    std::vector<int ,numb::allocator<int> > IV; //default allocator constructor
    
    // std::list<int,numb::allocator<int> >   IL;  //default allocator constructor
    for(int i=0;i!=2;i++)
    {
        IV.push_back(i);
        // IL.push_back(i);
    }
    // std::list<int,numb::allocator<int> >::iterator i = IL.begin();  
    // std::vector<int,numb::allocator<int> >::iterator j = IV.begin();  
  
    // std::cout<<"list:"<<std::endl;  
    // for(; i!= IL.end();++i)  
    //     std::cout<<*i<<" ";  
    // std::cout<<"\n\n";  
  
    // std::cout<<"vector:"<<std::endl;  
    // for(;j!= IV.end();++j)  
    //     std::cout<<*j<<" ";  
  
   return 0;
}