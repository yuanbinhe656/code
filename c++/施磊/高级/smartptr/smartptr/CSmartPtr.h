template<typename T>
class CSmartPtr {
public:
	CSmartPtr(T* ptr = nullptr) :m_ptr(ptr)
	{

	}
	// 利用栈上的对象出栈帧调用析构函数自动删除堆上的对象
	~CSmartPtr()
	{
		delete m_ptr;
	}
	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }
private:
	T* m_ptr;
};

