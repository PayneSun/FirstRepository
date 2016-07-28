// Proxy
// 2016.06.08


class Image;
extern Image* LoadAnImageFile(const char*);


class ImagePtr {
public:
    ImagePtr(const char* imageFile);
    virtual ~ImagePtr();
	
	virtual Image* operator->();
	virtual Image& operator*();
	
private:
	Image* LoadImage();
	Image* _image;
	const char* _imageFile;
};


Image* ImagePtr::LoadImage(const char* theImageFile) {
	_imageFile = theImageFile;
	_image = 0;
}


Image* ImagePtr::LoadImage() {
	if (_image == 0) {
		_image = LoadAnImageFile(_imageFile);
	}
	return _image;
}


Image* ImagePtr::operator->() {
	return LoadImage();
}


Image& ImagePtr::operator*() {
	return *LoadImage();
}


// Virtual Proxy Graphic
class Graphic {
public:
	virtual ~Graphic();
	virtual void Draw(const Point& at) = 0;
	virtual const Point& GetExtent() = 0;
	virtual void Load(istream& from) = 0;
	virtual void Save(ostream& to) = 0;
	
protected:
	Graphic();
};


class Image : public Graphic {
public:
	Image(const char* file);
	virtual ~Image();
	
	virtual void Draw(const Point& at);
	virtual void HandleMouse(Event& event);
	
	virtual const Point& GetExtent();
	virtual void Load(istream& from);
	virtual void Save(ostream& to);
	
private:
	// ...
};


class ImageProxy : public Graphic {
public:
	ImageProxy(const char* imageFile);
	
    virtual void Draw(const Point& at);
	virtual void HandleMouse(Event& event);
	
	virtual const Point& GetExtent();
	virtual void Load(istream& from);
	virtual void Save(ostream& to);

protected:
	Image* GetImage();
	
private:
	Image* _image;
	Point _extent;
	char* _fileName;
};


ImageProxy::ImageProxy(const char* fileName) {
	_fileName = strdup(fileName);
	_extent = Point::Zero;
	_image = 0;
}


Image* ImageProxy::GetImage() {
	if (_image == 0) {
		_image = new Image(_fileName);
	}
	return _image;
}


const Point& ImageProxy::GetExtent() {
	if (_extent == Point::Zero) {
		_extent = GetImage()->GetExtent();
	}
	return _extent;
}


void ImageProxy::Draw(const Point& at) {
	GetImage()->Draw(at);
}


void ImageProxy::HandleMouse(Event& event) {
	GetImage()->HandleMouse(event);
}
