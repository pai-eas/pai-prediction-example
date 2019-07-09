
## 本地调试

```bash
cd build/echo
sudo eascmd test service.json
[OK] Pulling image: registry.cn-shanghai.aliyuncs.com/eas/eas-worker-amd64:0.3.0
[OK] Pull image done
[OK] Create docker from: registry.cn-shanghai.aliyuncs.com/eas/eas-worker-amd64:0.3.0
[OK] Create docker: 5436a2f19221eb26a007df77d0732120621a22b8988ddb577a60e97152329606
[OK] Serving at: [http://localhost:6435/api/predict/test_echo]
[2019-07-09 17:56:22] [172.17.0.2] Fetching model from [http://059247.oss-cn-hangzhou-zmf.aliyuncs.com/scorecard.pmml]
[2019-07-09 17:56:22] [172.17.0.2] Fetching processor from [./echo_processor_release.tar.gz]
[2019-07-09 17:56:22] [172.17.0.2] ----------------------------SERVICE LOG--------------------------------
[2019-07-09 17:56:22] [172.17.0.2] Uncompressing model[/home/admin/docker_ml/workspace/model]
[2019-07-09 17:56:22] [172.17.0.2] Uncompressing processor[/home/admin/docker_ml/workspace/predictor]
[2019-07-09 17:56:22] [172.17.0.2] [INFO] env:SERVICE_CONFIG is merged into properties.
[2019-07-09 17:56:22] [172.17.0.2] [INFO] file:/home/admin/docker_ml/workspace//config/config.json is merged into properties.
[2019-07-09 17:56:22] [172.17.0.2] [WARN] set default headers for http:
[2019-07-09 17:56:22] [172.17.0.2] ============================
[2019-07-09 17:56:22] [172.17.0.2] Content-Type: text/html; charset=utf-8
[2019-07-09 17:56:22] [172.17.0.2] ============================
[2019-07-09 17:56:22] [172.17.0.2] Modifying property rpc.http.default_headers may crash a running service
[2019-07-09 17:56:22] [172.17.0.2] [INFO] ---- start creating unix-socket service
[2019-07-09 17:56:22] [172.17.0.2] [INFO] initialize new lua plugin
[2019-07-09 17:56:22] [172.17.0.2] [INFO] loading builtin config script
[2019-07-09 17:56:22] [172.17.0.2] [INFO] create ctrl socket
[2019-07-09 17:56:22] [172.17.0.2] [INFO] create service
[2019-07-09 17:56:22] [172.17.0.2] [INFO] bind service to /tmp/ctrl.socket
[2019-07-09 17:56:22] [172.17.0.2] [INFO] rpc binds to predefined port
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler call to /api/builtin/call
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler eastool to /api/builtin/eastool
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler monitor to /api/builtin/monitor
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler ping to /api/builtin/ping
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler prop to /api/builtin/prop
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler tell to /api/builtin/tell
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler term to /api/builtin/term
[2019-07-09 17:56:22] [172.17.0.2] [INFO] updating rpc port to
[2019-07-09 17:56:22] [172.17.0.2] [INFO] current meritc id:0
[2019-07-09 17:56:22] [172.17.0.2] [INFO] loading builtin lua scripts
[2019-07-09 17:56:22] [172.17.0.2] [INFO] Success load all lua scripts.
[2019-07-09 17:56:22] [172.17.0.2] [INFO] ---- start loading model
[2019-07-09 17:56:22] [172.17.0.2] [INFO] Creating processor [test_echo]
[2019-07-09 17:56:22] [172.17.0.2] [INFO] Processor api version: v2
[2019-07-09 17:56:22] [172.17.0.2] [INFO] Token: [fOURPXffwBWCawB4pq4XRCbPsOg=]
[2019-07-09 17:56:22] [172.17.0.2] [INFO] ---- start creating rpc service
[2019-07-09 17:56:22] [172.17.0.2] [INFO] create service
[2019-07-09 17:56:22] [172.17.0.2] [INFO] rpc binds to predefined port 8080
[2019-07-09 17:56:22] [172.17.0.2] [INFO] updating rpc port to 8080
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler call to /api/builtin/call
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler eastool to /api/builtin/eastool
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler monitor to /api/builtin/monitor
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler ping to /api/builtin/ping
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler prop to /api/builtin/prop
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler tell to /api/builtin/tell
[2019-07-09 17:56:22] [172.17.0.2] [INFO] install builtin handler term to /api/builtin/term
[2019-07-09 17:56:22] [172.17.0.2] [INFO] Start 5 worker thread
[2019-07-09 17:56:22] [172.17.0.2] [INFO] Service start successfully

```

通过上述命令拉起本地服务，服务地址为: [http://localhost:6435/api/predict/test_echo]，请求鉴权的token为：[fOURPXffwBWCawB4pq4XRCbPsOg=]

```bash
$curl http://localhost:6569/api/predict/test_echo -H 'Authorization:fOURPXffwBWCawB4pq4XRCbPsOg=' -d 'hello world'
{"modelfiles": "scorecard.pmml", "inputcontent", "hello world"}
```
