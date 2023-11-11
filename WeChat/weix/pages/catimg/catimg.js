// pages/catimg/catimg.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
      requesturl:"https://api.thecatapi.com/v1/images/search",
      imgurl:"https://cdn2.thecatapi.com/images/4tp.jpg",
      arrlist:[       
        { name:"选择猫猫种类"},
        { name:"abys"},
        { name:"Abyssinian"},
        { name:"bamb"},
        { name:"beng"},
        { name:"bure"}
       ],
       curIndex:0
  },

  /**
   * 生命周期函数--监听页面加载
   */
  selectimg(){
    let requesturl = this.data.requesturl
    let index = this.data.curIndex
    let catlog = this.data.arrlist[index].name
    let that = this
    // 未选择时，随机图片
    if(index == 0)
    {
      wx.request({
        url: requesturl,
        method:"GET",
        success(res){
          //请求成功
          if(res.statusCode==200)
          {
            that.setData({
              imgurl:res.data[0].url
          })
          }
          //请求失败
          else{
            wx.showModal({
              title: '温馨提示',
              content: '查询出错',
              showCancel:false
            
            })
            return
          }
        }
      })
    }
     //进行选择时，返回该种类的图片
    else{
      wx.request({
        url: requesturl,
        method:"GET",
        has_breeds:1,
        breed_ids:catlog,
        success(res){
          //请求成功
          if(res.statusCode==200)
          {
            that.setData({
              imgurl:res.data[0].url
          })
          }
          //请求失败
          else{
            wx.showModal({
              title: '温馨提示',
              content: '查询出错',
              showCancel:false
            
            })
            return
          }
        }
      })
    }

  },
  selectchang(e){
  
    this.setData({
      curIndex:e.detail.value
    })
  },
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