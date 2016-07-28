// Chain of Responsibility
// 2016.06.10


class HelpHandler {
public:
	HelpHandler(HelpHandler* s) : _successor(s) {}
	virtual void HandleHelp();

private:
	HelpHandler* _successor;
};


void HelpHandler::HandleHelp() {
	if (_successor) {
		_successor->HandleHelp();
	}
}


void Handler::HandleRequest(Request* theRequest) {
	switch(theRequest->GetKind()) {
		case Help:
			HandleHelp((HelpRequest*)theRequest);
			break;
		case Print:
			HandleHelp((PrintRequest*)theRequest);
			break;
		// ...
		default:
			// ...
			break;
	}
}


class ExtendHandler : public Handler {
public:
	virtual void HandleRequest(Request* theRequest);
	// ...
};


void ExtendHandler::HandleRequest(Request* theRequest) {
	switch(theRequest->GetKind()) {
		case Preview:
			// ...
			break;
		default:
			Handler::HandleRequest(theRequest);
	}
}


// Code for Example-------------------------------
typedef int Topic;
const Topic NO_HELP_TOPIC = -1;


class HelpHandler {
public:
	HelpHandler(HelpHandler* = 0, Topic = NO_HELP_TOPIC);
	virtual bool HasHelp();
	virtual bool SetHandler(HelpHandler*, Topic);
	virtual void HandleHelp();
	
private:
	HelpHandler* _successor;
	Topic _topic;
};


HelpHandler::HelpHandler(HelpHandler* h, Topic t
) : _successor(h), _topic(t) {}


bool HelpHandler::HasHelp() {
	return _topic != NO_HELP_TOPIC;
}


void HelpHandler::HandleHelp() {
	if (_successor != 0) {
		_successor->HandleHelp();
	}
}


class Widget : public HelpHandler {
protected:
	Widget(Widget* parent, Topic t = NO_HELP_TOPIC);

private:
	Widget* _parent;
};


Widget::Widget(Widget* w, Topic t) : HelpHandler(w, t) {
	_parent = w;
}


class Button : public Widget {
public:
	Button(Widget* d, Topic t = NO_HELP_TOPIC);

	virtual void HandleHelp();
};
