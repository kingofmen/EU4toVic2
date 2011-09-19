#ifndef V2PROVINCE_H_
#define V2PROVINCE_H_


#include "EU3World.h"
#include "V2Pop.h"


struct V2Demographic {
	string culture;
	string religion;
	double ratio;
	int oldProvinceID;
	string oldCountry;
};


class V2Province {
	public:
		void		init(int number);
		int		getNum();
		string	getName();
		void		setName(string);
		void		setOwner(string);
		string	getOwner();
		void		addCore(string);
		void		setColonial(bool);
		string	getCulture();
		void		setRgoType(string);
		string		getRgoType();
		void		setLifeRating(int);
		bool		isColonial();
		void		setColonised(bool);
		bool		wasColonised();
		void		addOldPop(V2Pop);
		void		output(FILE*);
		vector<V2Pop>	getPops(string type);
		void		addPopDemographic(V2Demographic d);
		void		doCreatePops(bool isStateCapital, int statePopulation, EU3World& sourceWorld);
		void		setCoastal(bool coastal);
		bool		isCoastal();
		int			getTotalPopulation() const;
		int			getOldPopulation() const;
		int			getSoldierPopForArmy(bool force = false);
		pair<int, int> getAvailableSoldierCapacity() const;
		string		getRegimentName(RegimentCategory rc);
		void		setFortLevel(int);
		void		setNavalBaseLevel(int);
	private:
		void		createPops(const V2Demographic& d, bool isStateCapital, int statePopulation, EU3Province* oldProvince, EU3Country* oldCountry);
		void		combinePops();
		bool		growSoldierPop(int popID);

		bool				land;
		bool				coastal;
		int				num;
		string			name;
		string			owner;
		//controller
		vector<string>	cores;
		bool				colonial;
		bool				colonised;
		int				oldPopulation;
		vector<V2Demographic> demographics;
		vector<V2Pop>	oldPops;
		vector<V2Pop>	pops;
		string			rgoType;
		int				lifeRating;
		int				unitNameCount[num_reg_categories];
		int				fortLevel;
		int				navalBaseLevel;
};


#endif // V2PROVINCE_H_