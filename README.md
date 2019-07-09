## 项目简介

本项目包含两个自定义processor的demo:
+ [**echo**] 请求时将用户输入原样返回，同时返回模型中的文件列表
+ [**image_classification**] mnist文本分类，输入mnist jpg图片，返回图片分类类别

## 项目编译

```
cd pai-prediction-example
mkdir build
cd build
cmake ..
make
```

## 项目运行

编译完成后会在build目录下生成echo，image_classification两个目录，在这两个目录执行如下命令可构建起单机版预测服务：

```
cd build/echo
sudo eascmd test service.json
```

两个项目的详细测试过程分别见两个源代码目录下的README

+ [**echo**] 
+ [**image_classification**] 
