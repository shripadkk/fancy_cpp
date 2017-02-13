#include <iostream>


template <typename T>
class scoped_refptr {
		  public:
					 scoped_refptr() : ptr_(NULL) {
					 }

					 scoped_refptr(T* p) : ptr_(p) {
								if (ptr_)
										  ptr_->AddRef();
					 }

					 scoped_refptr(const scoped_refptr<T>& r) : ptr_(r.ptr_) {
								if (ptr_)
										  ptr_->AddRef();
					 }

					 template <typename U>
								scoped_refptr(const scoped_refptr<U>& r) : ptr_(r.get()) {
										  if (ptr_)
													 ptr_->AddRef();
								}

					 // Move constructors.
					 scoped_refptr(scoped_refptr<T>&& r) : ptr_(r.release()) {}

					 template <typename U>
								scoped_refptr(scoped_refptr<U>&& r) : ptr_(r.release()) {}

					 ~scoped_refptr() {
								if (ptr_)
										  ptr_->Release();
					 }

					 T* get() const { return ptr_; }
					 operator T*() const { std::cout <<"Returning a value here";return ptr_; }
					 T* operator->() const { return ptr_; }

					 T* release() {
								T* retVal = ptr_;
								ptr_ = NULL;
								return retVal;
					 }

					 scoped_refptr<T>& operator=(T* p) {
								// AddRef first so that self assignment should work
								if (p)
										  p->AddRef();
								if (ptr_ )
										  ptr_ ->Release();
								ptr_ = p;
								return *this;
					 }

					 scoped_refptr<T>& operator=(const scoped_refptr<T>& r) {
								return *this = r.ptr_;
					 }

					 template <typename U>
								scoped_refptr<T>& operator=(const scoped_refptr<U>& r) {
										  return *this = r.get();
								}

					 scoped_refptr<T>& operator=(scoped_refptr<T>&& r) {
								scoped_refptr<T>(std::move(r)).swap(*this);
								return *this;
					 }

					 template <typename U>
								scoped_refptr<T>& operator=(scoped_refptr<U>&& r) {
										  scoped_refptr<T>(std::move(r)).swap(*this);
										  return *this;
								}


					 void swap(T** pp) {
								T* p = ptr_;
								ptr_ = *pp;
								*pp = p;
					 }

					 void swap(scoped_refptr<T>& r) {
								swap(&r.ptr_);
					 }

		  protected:
					 T* ptr_;
};


class temp {
		  public:
					 void AddRef() {}
					 void Release() {}
};
int main()
{
		  {
					 scoped_refptr<temp> b = new temp();
					 delete b;
		  }
		  std::cout<<" a clean exit";
}
