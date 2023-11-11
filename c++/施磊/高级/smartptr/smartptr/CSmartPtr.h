template<typename T>
class CSmartPtr {
public:
	CSmartPtr(T* ptr = nullptr) :m_ptr(ptr)
	{

	}
	// ����ջ�ϵĶ����ջ֡�������������Զ�ɾ�����ϵĶ���
	~CSmartPtr()
	{
		delete m_ptr;
	}
	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }
private:
	T* m_ptr;
};

