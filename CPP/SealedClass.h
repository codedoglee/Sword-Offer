#ifndef SEALEDCLASS_H_
#define SEALEDCLASS_H_

/*
 * 题目：用C++设计一个不能被继承的类
 */

//方法一：私有构造函数和析构函数
class SealedClass1 {
public:
	static SealedClass1* GetInstance() {
		return new SealedClass1();
	}
	static void DeleteInstance(SealedClass1* pInstance) {
		delete pInstance;
	}

private:
	SealedClass1() {}
	~SealedClass1() {}
};


//方法二：利用虚继承
template <typename T> class MakeSealed {
	friend T;
private:
	MakeSealed() {}
	~MakeSealed() {}
};
class SealedClass2 : virtual MakeSealed<SealedClass2> {
public:
	SealedClass2() {}
	~SealedClass2() {}
};


#endif /* SEALEDCLASS_H_ */
