#ifndef BILL_H
#define BILL_H

#include "Product.h"

class Bill : public Product
{
	private:
		char Bid[20], Total[20];
	public:
		Bill();
		~Bill();
    void SetBid(char *X) {
		strcpy(Bid, X);
	}
	char *GetBid() {
		return Bid;
	}
	void SetTotal(char *X) {
		strcpy(Total, X);
	}
	char* GetTotal() {
		return Total;
	}
	bool uniqe_ID(char key[]);
	void Add_Bill();
	void Add_Product_Bill();
};

#endif
