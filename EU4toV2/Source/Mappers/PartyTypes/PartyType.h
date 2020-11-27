#ifndef PARTY_TYPE_H
#define PARTY_TYPE_H
#include "Date.h"
#include "Parser.h"

namespace mappers
{
class PartyType: commonItems::parser
{
  public:
	PartyType() = default;
	explicit PartyType(std::istream& theStream);

	void setName(const std::string& partyName) { name = partyName; }
	void setIdeology(const std::string& theIdeology) { ideology = theIdeology; }
	
	[[nodiscard]] const auto& getName() const { return name; }
	[[nodiscard]] const auto& getIdeology() const { return ideology; }
	[[nodiscard]] const auto& getStartDate() const { return start_date; }
	[[nodiscard]] const auto& getEndDate() const { return end_date; }

	friend std::ostream& operator<<(std::ostream& output, const PartyType& partyDetails);

  private:
	void registerKeys();

	std::string name;
	std::string ideology;

	date start_date;
	date end_date;

	std::string economic_policy;
	std::string trade_policy;
	std::string religious_policy;
	std::string citizenship_policy;
	std::string war_policy;
};
} // namespace mappers

#endif // PARTY_TYPE_H