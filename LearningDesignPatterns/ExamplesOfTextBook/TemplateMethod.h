// TemplateMethod
// 2016.06.24


class {
};


void View::Display() {
	SetFoucus();
	DoDisplay();
	ResetFocus();
}


void View::DoDisplay() {
}


void MyView::DoDisplay() {
	// render the view's contents
}
