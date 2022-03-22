# pthread-macro
A pthread macro used in c++ class



## Demo

```shell
make
./a.out
```



## Example

If you want to add a thread named `bg_func` to the class named `my_class`. You can use follow example:

```c++
BACKGROUND_WORKER(my_class, bg_func)
{
    //... Do Something    
}
```

- class 

```c++
#include "my_macro.hpp"
...
class my_class
{
    // ...
    BACKGROUND_WORKER(my_class, bg_func)
    {
        //... Do Something  
    }
    // ...
}
```

- main

```c++
int main(void)
{
    my_class cc;
    cc.bg_func_Start();
    PAUSE;
    cc.bg_func_Close(); // force destory
}
```



## Detail

### 有關巨集展開

其實巨集`BACKGROUND_WORKER`由

```c++
class my_class
{
    BACKGROUND_WORKER(my_class, bg_func)
    {
        //... Do Something
    }
}
```

展開像這樣

```C++
#define BACKGROUND_WORKER(ClassName, ThreadName)   \
    BACKGROUND_WORKER_START(ClassName, ThreadName) \
    BACKGROUND_WORKER_CLOSE(ClassName, ThreadName) \
    BACKGROUND_WORKER_DOWORK(ClassName, ThreadName)
```

是由下方程式設計設計而來

```c++
class my_class
{
    // BACKGROUND_WORKER_CLOSE(cName, bgName)
public:
    void bg_func_Close(void)
    {
        pthread_cancel(this->bg_func_id);
    }
    
    // BACKGROUND_WORKER_START(cName, bgName)  
public:
    void bg_func_Start(void)
    {
        pthread_create(&bg_func_id, NULL, &cName::bg_func_sLink, this);
    }
    
    // BACKGROUND_WORKER_DOWORK(cName, bgName)
private:
    pthread_t bg_func_id;
    
private:
    static void *bg_func_sLink(void *iContext)
    {
        return ((cName *)iContext)->bg_func_DoWork();
    }

private:
    void *bg_func_DoWork(void)
    {
        //... Do Something    
    }
    
}
```



### 有關sLink與DoWork函數

這是一種寫法為了讓pthread建立的執行序函數，可以用`this`存取class之中的成員所設計的

參考

https://stackoverflow.com/a/1151638/9096859

https://stackoverflow.com/questions/1151582/pthread-function-from-a-class
