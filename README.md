# Setup

1. Download MinGW compiler.
2. Download and open Visual Studio Code.
3. Open the project, then navigate to the folder named `vector`.
4. Open the terminal and execute the following commands:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ./my_program
    ```
5. Enjoy!

 ## Experiment nr1 <br>
 ### file generation <br>
 <b> 1000 file <b> took 0.025852 s <br>
 <b> 10000 file <b> took 0.083931 s <br>
 <b> 100000 file <b> took 0.900715 s <br>
 <b> 1000000 file <b> took 9.59604 s <br>
 <b> 10000000 file <b> took 76.1765 s <br>
 ![Experiment1.png](https://github.com/Edukasas/Obj-programming/blob/V0.4/assets/1tyrimas.png)<br>
 ## Experiment nr2 <br>
  <b> 1000 file <b> took to read and sort 0.028622 s, to output 0.032415, all 0.0639 s<br>
  ![img](https://github.com/Edukasas/Obj-programming/blob/V0.4/assets/1000.png)<br>
  <b> 10000 file <b> took to read and sort 0.178939 s, to output 0.226061, all 0.405 s<br>
    ![img](https://github.com/Edukasas/Obj-programming/blob/V0.4/assets/10000.png)<br>
  <b> 100000 file <b> took to read and sort 2.51716 s, to output 2.81637 s, all 5.33353 s<br>
    ![img](https://github.com/Edukasas/Obj-programming/blob/V0.4/assets/100000.png)<br>
  <b> 1000000 file <b> took to read and sort 23.0932 s, to output 17.8884 s, all 40.9816 s <br>
    ![img](https://github.com/Edukasas/Obj-programming/blob/V0.4/assets/1000000.png)<br>
  <b> 10000000 file <b> took to read and sort 204.185 s, to output 291.55 s, all 495.736 s<br>
    ![img](https://github.com/Edukasas/Obj-programming/blob/V0.4/assets/10000000.png)<br>
# Experiment with different STL containers <br>
## Strategy 1
### Deque <br>
 <b> 1000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque1.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque1a.png)<br><br>
 <b> 10000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque2.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque2a.png)<br><br>
 <b> 100000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque3.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque3a.png)<br><br>
 <b> 1000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque4.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque4a.png)<br><br>
 <b> 10000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque5.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque5a.png)<br><br>
### Vector <br>
 <b> 1000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector1.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector1a.png)<br><br>
 <b> 10000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector2.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector2a.png)<br><br>
 <b> 100000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector3.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector3a.png)<br><br>
 <b> 1000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector4.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector4a.png)<br><br>
 <b> 10000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector5.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector5a.png)<br><br>
### List <br>
 <b> 1000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list1.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list1a.png)<br><br>
 <b> 10000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list2.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list2a.png)<br><br>
 <b> 100000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list3.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list3a.png)<br><br>
 <b> 1000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list4.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list4a.png)<br><br>
 <b> 10000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list5.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list5a.png)<br><br>
  ## Strategy 2
### Deque <br>
 <b> 1000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque6.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque6a.png)<br><br>
 <b> 10000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque7.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque7a.png)<br><br>
 <b> 100000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque8.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque8a.png)<br><br>
 <b> 1000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque9.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque9a.png)<br><br>
 <b> 10000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque10.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque10a.png)<br><br>
### Vector <br>
 <b> 1000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector6.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector6a.png)<br><br>
 <b> 10000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector7.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector7a.png)<br><br>
 <b> 100000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector8.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector8a.png)<br><br>
 <b> 1000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector9.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector9a.png)<br><br>
 <b> 10000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector10.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector10a.png)<br><br>
### List <br>
 <b> 1000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list6.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list6a.png)<br><br>
 <b> 10000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list7.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list7a.png)<br><br>
 <b> 100000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list8.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list8a.png)<br><br>
 <b> 1000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list9.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list9a.png)<br><br>
 <b> 10000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list10.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list10a.png)<br><br>
  ## Strategy 3
### Deque <br>
 <b> 1000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque11.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque11a.png)<br><br>
 <b> 10000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque12.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque12a.png)<br><br>
 <b> 100000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque13.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque13a.png)<br><br>
 <b> 1000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque14.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque14a.png)<br><br>
 <b> 10000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque15.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/deque15a.png)<br><br>
### Vector <br>
 <b> 1000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector11.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector11a.png)<br><br>
 <b> 10000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector12.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector12a.png)<br><br>
 <b> 100000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector13.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector13a.png)<br><br>
 <b> 1000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector14.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector14a.png)<br><br>
 <b> 10000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector15.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/vector15a.png)<br><br>
### List <br>
 <b> 1000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list11.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list11a.png)<br><br>
 <b> 10000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list12.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list12a.png)<br><br>
 <b> 100000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list13.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list13a.png)<br><br>
 <b> 1000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list14.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list14a.png)<br><br>
 <b> 10000000 file <b><br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list15.png)
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/list15a.png)<br><br>
### Average <br>
1 000 file with the best optimization <br>
<b>Vector</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/average1.png) <br>
<b>List</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/average1.png) <br>
<b>Deque</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/average1.png) <br>
10 000 file with the best optimization <br>
<b>Vector</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/average2.png) <br>
<b>List</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/average2.png) <br>
<b>Deque</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/average2.png) <br>
100 000 file with the best optimization <br>
<b>Vector</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/average3.png) <br>
<b>List</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/average3.png) <br>
<b>Deque</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/average3.png) <br>
1 000 000 file with the best optimization <br>
<b>Vector</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/average4.png) <br>
<b>List</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/average4.png) <br>
<b>Deque</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/average4.png) <br>

10 000 000 file with the best optimization <br>
<b>Vector</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Vector/average5.png) <br>
<b>List</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/List/average5.png) <br>
<b>Deque</b> <br>
![img](https://github.com/Edukasas/Obj-programming/blob/V1.0/assets/V1.0/Deque/average5.png) <br>
## Container efficiency summary <br>

# Releases
### Release v0.1 <br>
 You can generate marks as well as name and surname by running c.cpp or vector c.pp<br>
 ### Release v0.2 <br>
 You can read data from a file<br>
 ### Release v0.3 <br>
 Implementation of try/catch, multi function file <br>
 ### Release v0.4 <br>
 Can generate files as well as distributes students into two different containers, the below 5 and the rest<br>
 ### Release V1.0 <br>
 Implementation of 3 different STL containers and finding the fastest way of sorting them<br>


 

 
 
 
 
