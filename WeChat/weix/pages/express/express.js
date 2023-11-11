// pages/express/express.js
// 导入外部文件 
const md5 = require("../../utils/md5.js")
const base64 = require("../../utils/base64.js")

Page({

  /**
   * 页面的初始数据
   */
  data: {
     arrlist:[
       {id:0,name:"请选择快递公司"},
       {id:"YTO",name:"圆通速递"},
       {id:"STO",name:"申通快递"},
       {id:"HTKY",name:"百世快递"}
     ],
     curIndex:0,
     myLogistiCode:'',
     reusltList:[]
  },
  // 选择快递公司
  changeEnterprise(e){
    // 把下拉选择器的选中的索引,赋值给curIndex
    this.setData({curIndex:e.detail.value})
  },

  //获取输入框内容--单号
  onInputChange(ee) {
    this.setData({myLogistiCode : ee.detail.value})
},

  // 获得扫描二维码
  getCode(){
    let that = this
    // 调用wx的扫描二维码的api
    wx.scanCode({
      success:function(res){
        that.setData({myLogistiCode:res.result})
      }
    })
  },
  // 根据快递单和快递公司查询物流轨迹
  getExpressList(){
    /**
     * 实现思路
     * 1.获得快递单号和快递公司
     * 2.验证数据有效性，不合格，提示用户
     * 3.去远程获取物流轨迹信息，并绑定到页面
     */
    let that = this
    // 1.获得快递单号和快递公司
    let logistiCode = this.data.myLogistiCode
    let shipperCode = this.data.arrlist[this.data.curIndex].id
    console.log(logistiCode)
    console.log(shipperCode)
    // 2.验证数据有效性，不合格，提示用户
    if(logistiCode=="" || logistiCode.trim()==""){
      wx.showModal({
        title:"温馨提示",
        content:"快递单号不能为空",
        showCancel:false
      })
      return
    }
    if(shipperCode==0){
      wx.showModal({
        title:"温馨提示",
        content:"请选择快递公司",
        showCancel:false
      })
      return
    }
    // 3.去远程获取物流轨迹信息，并绑定到页面
    // 3.1 请稍等
    wx.showLoading({
      title: '请稍等...',
    })
    // 3.2 发送异步请求
    wx.request({
      method:"POST",
      header:{"content-type":"application/x-www-form-urlencoded;charset=utf-8"},
      url: 'https://api.kdniao.com/Ebusiness/EbusinessOrderHandle.aspx',
      data:this.getParamters(logistiCode,shipperCode),
      success(res){
        // 数据判断
        if(res.statusCode==200){
          // 判断是否有物流轨迹
           if(res.data.Traces!=undefined && res.data.Traces.length>0){//有物流轨迹
               that.setData({reusltList:res.data.Traces.reverse()})
               console.log(that.data.reusltList)
           }
           else{//没有查询物流轨迹
            wx.showModal({
              title:"温馨提示",
              content:"没有查询物流轨迹",
              showCancel:false
            })
            return
           }
        }
        else{// 查询数据出错了
          wx.showModal({
            title:"温馨提示",
            content:"查询数据出错了",
            showCancel:false
          })
          return
        }
      },
      complete(comres){
        // 隐藏loading
        wx.hideLoading()
      }
    })
  },
  getParamters(logistiCode,shipperCode){
      // 请求的指令
      const RequestType = "1002"
      // APiKey
      const ApiKey = "0bb028ad-df87-462c-be33-fd10142901a0"
      // 用户ID
      const EBusinessID = "1427364"
      // 请求参数
      const RequestData= {
        "ShipperCode": shipperCode,
        "LogisticCode": logistiCode
      }
     // 数据加密(先md5,再base64)
     const DataSign =base64.encode(md5.hexMD5(JSON.stringify(RequestData)+ApiKey)) 
     // 封装参数数据
     const reqParmaters={
       RequestType,
       EBusinessID,
       DataSign,
       RequestData: JSON.stringify(RequestData),
       DataType:2
     }
     return reqParmaters
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady() {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide() {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload() {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {

  }
})