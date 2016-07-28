// Visitor
// 2016.06.24


class Visitor {
public:
	virtual void VisitElementA(ElementA*);
	virtual void VisitElementB(ElementB*);
	// ...

protected:
	Visitor();
};


class Element {
public:
	virtual ~Element();
	virtual void Accept(Visitor&) = 0;

protected:
	Element();
};


class ElementA : public Element {
public:
	ElementA();
	virtual void Accept(Visitor& v) {
		v.VisitElementA(this);
	}
};


class ElementB : public Element {
public:
	ElementB();
	virtual void Accept(Visitor& v) {
		v.VisitElementB(this);
	}
};


class CompositeElement : public Element {
public:
	virtual void Accept(Visitor&);

private:
	List<Element*>* _children;
};


void CompositeElement::Accept(Visitor& v) {
	ListIterator<Element*> i(_children);
	
	for (i.First(); !i.IsDone(); i.Next()) {
		i.CurrentItem()->Accept(v);
	}
	v.VisitCompositeElement(this);
}


class Equipment {
public:
	virtual ~Equipment();
	
	const char* Name() { return _name; }
	
	virtual Watt Power();
	virtual Currency NetPrice();
	virtual Currency DiscountPrice();
	
	virtual void Accept(EquipmentVisitor&);
	
protected:
	Equipment(const char*);

private:
	const char* _name;
};


class EquipmentVisitor {
public:
	virtual ~EquipmentVisitor();
	virtual void VisitFloppyDisk(FloppyDisk*);
	virtual void VisitCard(Card*);
	virtual void VisitChassis(Chassis*);
	virtual void VisitBus(Bus*);

protected:
	EquipmentVisitor();
};


void FloppyDisk::Accept(EquipmentVisitor& visitor) {
	visitor.VisitFloppyDisk(this);
}


void Chassis::Accept(EquipmentVisitor& visitor) {
	for (
		ListIterator<Equipment*> i(_parts);
	    !i.IsDone();
		i.Next()
	) {
		i.CurrentItem()->Accept(visitor);
	}
	visitor.VisitChassis(this);
}


class PricingVisitor : public EquipmentVisitor {
public:
	PricingVisitor();
	Currency& GetTotalPrice();

	virtual void VisitFloppyDisk(FloppyDisk*);
	virtual void VisitCard(Card*);
	virtual void VisitChassis(Chassis*);
	virtual void VisitBus(Bus*);

private:
	Currency _total;
};


void PricingVisitor::VisitFloppyDisk(FloppyDisk* fd) {
	_total += fd->NetPrice();
}


void PricingVisitor::VisitChassis(Chassis* c) {
	_total += c->DiscountPrice();
}


class InventoryVisitor : public EquipmentVisitor {
public:
	InventoryVisitor();
	Inventory& GetInventory();
	
	virtual void VisitFloppyDisk(FloppyDisk*);
	virtual void VisitCard(Card*);
	virtual void VisitChassis(Chassis*);
	virtual void VisitBus(Bus*);
	// ...
	
private:
	Inventory _inventory;
};


void InventoryVisitor::VisitFloppyDisk(FloppyDisk* fd) {
	_inventory.Accumulate(fd);
}


void InventoryVisitor::VisitChassis(Chassis* c) {
	_inventory.Accumulate(c);
}


Equipment* component;
InventoryVisitor visitor;

component->Accept(visitor);
