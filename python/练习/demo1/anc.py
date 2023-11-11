# coding=UTF-8
import requests
host = 'https://wuliu.market.alicloudapi.com'
path = '/kdi'
method = 'GET'
appcode = '你自己的AppCode'#开通服务后 买家中心-查看AppCode
querys = 'no=780098068058&type=zto'
bodys = {}
url = host + path + '?' + querys
header = {"Authorization":'APPCODE ' + appcode}
try:
    res = requests.get(url,headers=header)
except :
    print("URL错误")
    exit()
httpStatusCode = res.status_code

if(httpStatusCode == 200):
    print("正常请求计费(其他均不计费)")
    print(res.text)
else:
    httpReason = res.headers['X-Ca-Error-Message']
    if(httpStatusCode == 400 and httpReason == 'Invalid Param Location'):
        print("参数错误")
    elif(httpStatusCode == 400 and httpReason == 'Invalid AppCode'):
        print("AppCode错误")
    elif(httpStatusCode == 400 and httpReason == 'Invalid Url'):
        print("请求的 Method、Path 或者环境错误")
    elif(httpStatusCode == 403 and httpReason == 'Unauthorized'):
        print("服务未被授权（或URL和Path不正确）")
    elif(httpStatusCode == 403 and httpReason == 'Quota Exhausted'):
        print("套餐包次数用完")
    elif(httpStatusCode == 403 and httpReason == 'Api Market Subscription quota exhausted'):
        print("套餐包次数用完，请续购套餐")
    elif(httpStatusCode == 500 ):
        print("API网关错误")
    else:
        print("参数名错误 或 其他错误")
        print(httpStatusCode)
        print(httpReason)