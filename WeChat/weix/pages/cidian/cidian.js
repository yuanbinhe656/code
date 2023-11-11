//index.js
Page({

 /**
 * 页面的初始数据
 */
 data: {
 result:'',
 tip:''
 },

 /**
 * 自定义函数--监听表单提交并查成语
 */
 search: function (e) {
 var that = this
 // 获取成语单词
 let chengyu = e.detail.value.chengyu

 // 没有输入任何内容
 if (chengyu == '') {
wx.showToast({
 title: '成语不能为空！',
 icon: 'none'
 })
 }
// 发起网络请求
else {
 wx.request({
 url: 'https://apis.juhe.cn/idioms/query',
 data: {
 wd: chengyu,
 key: '23145d4e1fa869ceafd65f7f4567334c'
 },
 success: function (res) {
 console.log(res.data)
 // 查到结果了
 if (res.data.error_code == 0) {
 that.setData({
 result: res.data.result,
 tip:''
 })
 }
 // 查无此词
else{
 that.setData({
 result:'',
 tip:'查询不到该成语的相关信息。'
 })
 }
 }
})
 }
}, })