
## 本地调试

```bash
cd build/echo
sudo eascmd test service.json
[OK] Pulling image: registry.cn-shanghai.aliyuncs.com/eas/easworker:v0.0.6
[OK] Pull image done
[OK] Create docker from: registry.cn-shanghai.aliyuncs.com/eas/easworker:v0.0.6
[OK] Create docker: a901b984d8c7b72bc54e85ea50b23d41fd96b4cce61d837e4d678b6673611658
[OK] Create processor from ./echo_processor_release.tar.gz
[OK] Update predictor complete!
[OK] Create model from http://059247.oss-cn-hangzhou-zmf.aliyuncs.com/scorecard.pmml
[OK] Update model complete [TOKEN: R+gAg3dbTMmHKD4YH6gXABgGuSY=]
[OK] Serving at: http://localhost:6569/api/predict/test_echo
```

通过上述命令拉起本地服务，服务地址为: [http://localhost:6569/api/predict/test_echo]，请求鉴权的token为：[R+gAg3dbTMmHKD4YH6gXABgGuSY=]

```bash
$curl http://localhost:6569/api/predict/test_echo -H 'Authorization:R+gAg3dbTMmHKD4YH6gXABgGuSY=' -d 'hello world'
{"modelfiles": "scorecard.pmml", "inputcontent", "hello world"}
```
