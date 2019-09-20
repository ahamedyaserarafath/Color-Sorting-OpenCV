# Gems color sorting using opencv C++
- [Introduction](#Introduction)
- [Pre-requisites](#pre-requisites)
- [Steps to run script](#Steps-to-run-script)

# Introduction
In this repo, we will use opencv to detect the basic color of gems

# Pre-requisites 
* Ensure you install the g++ and opencv

# Steps to run script
```
g++ `pkg-config opencv --cflags --libs` gems_color_sorting.c -o output

```
```
./output ./gems/Photo0769.jpg ./gems/Photo0776.jpg ./gems/Photo0777.jpg ./gems/Photo0778.jpg ./gems/Photo0779.jpg ./gems/Photo0778.jpg ./gems/Photo0777.jpg ./gems/Photo0769.jpg
```
