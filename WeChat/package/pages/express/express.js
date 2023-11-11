// pages/express/express.js
//导入外部文件
const md5=require("../../utils/md5.js")
const base64=require("../../utils/base64.js")
Page({

  /**
   * 页面的初始数据
   */
  data: {
      arrlist:[
        {id:"0",name:"请选择快递公司"},
        {id:"YTO",name:"圆通速递",},
        {id:"STO",name:"申通快递",},
        {id:"HTKY",name:"百世快递",},
      ],
      curIndex:0,
      myLogistiCode:'',
      requestlist:[],
      iconselctlist:[
        {id:"0",icon:"success"},
        {id:"1",icon:"warn"},
        {id:"2",icon:"waiting"}
      ],
      inconIndex:0,

  },

  changeEnterprise(e){
    //将下拉选择器选项赋值给curIndex
    this.setData({curIndex:e.detail.value});
  
  
  },
  //扫描二维码函数
  getCode(){
    //调用微信扫描二维码API
    let that = this
    
    wx.scanCode({
     success:function(res){
      that.setData({myLogistiCode:res.result})      
     }
    })
  },
  //根据物流单号查询到物流轨迹
  getExpressList(){
  /**
   * 实现思路
   * 1.获得快递号和快递公司
   * 2.验证数据有效性，不合格，提示用户
   * 3.远程获取物流的轨迹信息，并绑定到界面 */  
  //1.获得快递号和快递公司
    let that=this
    let logistiCode = this.data.myLogistiCode
    let shipperCode = this.data.arrlist[this.data.curIndex].id
    console.log(logistiCode)
    console.log(shipperCode)
    //2.验证数据有效性，不合格，提示用户
    if(logistiCode==""|| logistiCode.trim()=="")
    {
      wx.showModal({
        title: '温馨提示',
        content: '快递单号不为空',
        showCancel:false
      })
      return
    }
    if(shipperCode==0)
    {
      wx.showModal({
        title: '温馨提示',
        content: '请选择快递公司',
        showCancel:false
      })
      return
    }
    // 3.远程获取物流的轨迹信息，并绑定到界面 
    // 3.1 异步通信
    wx.showLoading({
      title: '请等待',
    })
    //3.2发送异步请求
    wx.request({
      method:"POST",
      header:{"content-type":"application/x-www-form-urlencoded;charset=utf-8"},
      url: 'https://api.kdniao.com/Ebusiness/EbusinessOrderHandle.aspx',
      data:this.getParamters(logistiCode,shipperCode),
      success(res)
      {
        wx.hideLoading()
        console.log(res)
        if(res.statusCode == 200)  //查询返回成功
        {
          if(res.data.Traces!=undefined && res.data.Traces.length>0) // 查询数据不为空
          {
            that.setData({requestlist:res.data.Traces.reverse()})
            if(res.data.State =="3")
            {
              that.setData({inconIndex:0})
              console.log(that.data.inconIndex)
            }
            else if(res.data.State >"3")
            {
              that.setData({inconIndex:1})
            }
            else if(res.data.State <"3")
            {
              that.setData({inconIndex:2})
            }
            
          }
          else{  //查询数据为空
            wx.showModal({
              title: '温馨提示',
              content: '查询出错',
              showCancel:false
            
            })
            return
          }
        }
        else{  //未查询到数据
          wx.showModal({
            title: '温馨提示',
            content: '查询出错',
            showCancel:false
          
          })
          return
        }
      }
    })


  },
  //请求参数编码
  getParamters(logistiCode,shipperCode){
    //请求指令码
    const RequestType = "1002"
    // APPIkey
    const APIKey = "ccedd9ab-24dc-4f70-b9d3-2f2fdbbe527a"
    // 用户ID
    const EBusinessID="1806312"
    // 请求参数
    const RequestData = {
      "ShipperCode": shipperCode,
      "LogisticCode":logistiCode
   }
   // md4加密 base64编码
    //3.3数据加密(先md5，在base64)
    const DataSign = base64.encode(md5.hexMD5(JSON.stringify(RequestData) + APIKey))
    const reqParmaters={
      RequestType,
      DataSign,
      EBusinessID,
      
      RequestData:JSON.stringify(RequestData),
      DataType: "2",


    }
    return reqParmaters
  },
  /**
   * 生命周期函数--监听页面加载
   * 
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