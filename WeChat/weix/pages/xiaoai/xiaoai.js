// pages/xiaoai/xiaoai.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    requesturl:"https://v.api.aa1.cn/api/api-xiaoai/talk.php",
    chatdata:"",
    par:"xiaoai",
    me:"me",
    focus:true,
    bottom:"",
    chathistory:[

    ]
    // {name:"me",data:"hgagg"},
    // {name:"xiaoai",data:"hgaggggggggggggggggggggfffffggggggggggggadfagh"},
    // {name:"me",data:"hgagg"},
    // {name:"xiaoai",data:"hgagg"},
    // {name:"me",data:"hgagg"},
    // {name:"xiaoai",data:"hgagg"},
    // {name:"me",data:"hgagg"},
    // {name:"xiaoai",data:"hgagg"},
    // {name:"me",data:"hgagg"},
    // {name:"xiaoai",data:"hgagg"},
    // {name:"me",data:"hgagg"},
    // {name:"xiaoai",data:"hgagg"},
    // {name:"me",data:"hgagg"},
    // {name:"xiaoai",data:"hgagg"},
    // {name:"me",data:"hgagg"},
    // {name:"xiaoai",data:"hgagg"}


  },
  tobtoom(){

  },
  send(){
      
    let chatdata = this.data.chatdata

    if(chatdata=="")
    {
      return
    }
    this.setData({
      chatdata:"",
      focus:true,
      bottom:"bottom"
    }
     
    )
    
   
    var adddata={}
    adddata.name="me"
    adddata.data=chatdata
    let his = this.data.chathistory
    his.push(adddata)
    this.setData({
      chathistory:his
    })
    let that = this
    let requesturl = this.data.requesturl

   
    wx.request({
      url: requesturl,
      method: "GET",
      data:{
        msg:chatdata
      },
      

      success: (res) => {
    
    var adddat={}
    adddat.name="xiaoai"
    adddat.data=res.data
    let his = that.data.chathistory
    his.push(adddat)
    that.setData({
      chathistory:his,
      bottom:"bottom"
    })
     


      },
      fail: (err) => {
        var adddat={}
        adddat.name="xiaoai"
        adddat.data="请查看网络连接"
        let his = that.data.chathistory
        his.push(adddat)
        that.setData({
          chathistory:his,
          bottom:"bottom"
        })  
      },
      complete: (res) => {},
    })
  },
  refoucs(){
    if(this.data.chatdata=="")
    {
      
    }
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