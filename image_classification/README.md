
## 本地调试

```bash
$ cd build/image_classification
$ sudo eascmd test service.json
[OK] Pulling image: registry.cn-shanghai.aliyuncs.com/eas/eas-worker-amd64:0.3.0
[OK] Pull image done
[OK] Create docker from: registry.cn-shanghai.aliyuncs.com/eas/eas-worker-amd64:0.3.0
[OK] Create docker: 4e7111bf4bda7a41092ed4653495cb159754f26e6c6c6c3d3e630b3cc33c1352
[OK] Serving at: [http://localhost:5726/api/predict/mnist_image_classification]
[2019-07-09 18:12:38] [172.17.0.2] Fetching model from [http://eas-data.oss-cn-shanghai.aliyuncs.com/models/saved_model.tar.gz]
[2019-07-09 18:12:39] [172.17.0.2] Fetching processor from [./image_classification_processor_release.tar.gz]
[2019-07-09 18:12:39] [172.17.0.2] ----------------------------SERVICE LOG--------------------------------
[2019-07-09 18:12:39] [172.17.0.2] Uncompressing model[/home/admin/docker_ml/workspace/model]
[2019-07-09 18:12:39] [172.17.0.2] Uncompressing processor[/home/admin/docker_ml/workspace/predictor]
[2019-07-09 18:12:40] [172.17.0.2] [INFO] env:SERVICE_CONFIG is merged into properties.
[2019-07-09 18:12:40] [172.17.0.2] [INFO] file:/home/admin/docker_ml/workspace//config/config.json is merged into properties.
[2019-07-09 18:12:40] [172.17.0.2] [WARN] set default headers for http:
[2019-07-09 18:12:40] [172.17.0.2] ============================
[2019-07-09 18:12:40] [172.17.0.2] Content-Type: text/html; charset=utf-8
[2019-07-09 18:12:40] [172.17.0.2] ============================
[2019-07-09 18:12:40] [172.17.0.2] Modifying property rpc.http.default_headers may crash a running service
[2019-07-09 18:12:40] [172.17.0.2] [INFO] ---- start creating unix-socket service
[2019-07-09 18:12:40] [172.17.0.2] [INFO] initialize new lua plugin
[2019-07-09 18:12:40] [172.17.0.2] [INFO] loading builtin config script
[2019-07-09 18:12:40] [172.17.0.2] [INFO] create ctrl socket
[2019-07-09 18:12:40] [172.17.0.2] [INFO] create service
[2019-07-09 18:12:40] [172.17.0.2] [INFO] bind service to /tmp/ctrl.socket
[2019-07-09 18:12:40] [172.17.0.2] [INFO] rpc binds to predefined port
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler call to /api/builtin/call
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler eastool to /api/builtin/eastool
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler monitor to /api/builtin/monitor
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler ping to /api/builtin/ping
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler prop to /api/builtin/prop
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler tell to /api/builtin/tell
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler term to /api/builtin/term
[2019-07-09 18:12:40] [172.17.0.2] [INFO] updating rpc port to
[2019-07-09 18:12:40] [172.17.0.2] [INFO] current meritc id:0
[2019-07-09 18:12:40] [172.17.0.2] [INFO] loading builtin lua scripts
[2019-07-09 18:12:40] [172.17.0.2] [INFO] Success load all lua scripts.
[2019-07-09 18:12:40] [172.17.0.2] [INFO] ---- start loading model
[2019-07-09 18:12:40] [172.17.0.2] [INFO] Creating processor [mnist_image_classification]
[2019-07-09 18:12:40] [172.17.0.2] [INFO] Processor api version: v2
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.805934: I /home/xingke.lwp/code/docker_ml/processor/tensorflow/src/saved_model_loader.cpp:214] Attempting to load native SavedModel from /home/admin/docker_ml/workspace//model/./1/
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.806106: I tensorflow/cc/saved_model/reader.cc:31] Reading SavedModel from: /home/admin/docker_ml/workspace//model/./1/
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.806995: I tensorflow/cc/saved_model/reader.cc:54] Reading meta graph with tags { serve }
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.886517: I tensorflow/cc/saved_model/loader.cc:162] Restoring SavedModel bundle.
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.901366: I tensorflow/cc/saved_model/loader.cc:138] Running MainOp with key legacy_init_op on SavedModel bundle.
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.909436: I tensorflow/cc/saved_model/loader.cc:259] SavedModel load for tags { serve }; Status: success. Took 103328 microseconds.
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.909485: I /home/xingke.lwp/code/docker_ml/processor/tensorflow/src/saved_model_loader.cpp:222] Show SignatureDef Information:
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.909499: I /home/xingke.lwp/code/docker_ml/processor/tensorflow/src/saved_model_loader.cpp:231] Inputs:
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.909518: I /home/xingke.lwp/code/docker_ml/processor/tensorflow/src/saved_model_loader.cpp:255] images: [-1, 784]; DT_FLOAT
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.909526: I /home/xingke.lwp/code/docker_ml/processor/tensorflow/src/saved_model_loader.cpp:259] Outputs:
[2019-07-09 18:12:40] [172.17.0.2] 2019-07-09 18:12:40.909536: I /home/xingke.lwp/code/docker_ml/processor/tensorflow/src/saved_model_loader.cpp:286] scores: [-1, 10]; DT_FLOAT
[2019-07-09 18:12:40] [172.17.0.2] [INFO] Token: [kF9CnrAprsanjjupn8HLg1oiMQA=]
[2019-07-09 18:12:40] [172.17.0.2] [INFO] ---- start creating rpc service
[2019-07-09 18:12:40] [172.17.0.2] [INFO] create service
[2019-07-09 18:12:40] [172.17.0.2] [INFO] rpc binds to predefined port 8080
[2019-07-09 18:12:40] [172.17.0.2] [INFO] updating rpc port to 8080
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler call to /api/builtin/call
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler eastool to /api/builtin/eastool
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler monitor to /api/builtin/monitor
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler ping to /api/builtin/ping
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler prop to /api/builtin/prop
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler tell to /api/builtin/tell
[2019-07-09 18:12:40] [172.17.0.2] [INFO] install builtin handler term to /api/builtin/term
[2019-07-09 18:12:40] [172.17.0.2] [INFO] Start 5 worker thread
[2019-07-09 18:12:40] [172.17.0.2] [INFO] Service start successfully
```

通过上述命令拉起本地服务，服务地址为: \[http://localhost:4279/api/predict/mnist_image_classification\]，请求鉴权的token为：\[kF9CnrAprsanjjupn8HLg1oiMQA=\]

```bash
curl http://localhost:5726/api/predict/mnist_image_classification -H 'Authorization:kF9CnrAprsanjjupn8HLg1oiMQA=' --data-binary '@image_classification/test_images/9.jpg'
{"result": 9}
```
