#include "Highs.h"
#include <cassert>

using std::cout;
using std::endl;

int main()
{
    Highs highs;

    // [[maybe_unused]] HighsStatus highs_status = highs.passModel(model);

    [[maybe_unused]] HighsStatus highs_status = highs.readModel("/home/ivet/code/instance.mps");

    assert(highs_status == HighsStatus::kOk);

    // highs_status = setInitialSolution(highs); //  creats a HighsSolution modifies its highsSolution.col_value and calls highs.setSolution(highsSolution);
    assert(highs_status == HighsStatus::kOk);

    highs.setOptionValue("primal_feasibility_tolerance", 0.005);
    highs.setOptionValue("dual_feasibility_tolerance", 0.005);
    highs.setOptionValue("ipm_optimality_tolerance", 0.05); // i know that it makes no sense if the solver is not ipm, but expect it to  simply be ignored
    highs.setOptionValue("solver", "pdlp");
    highs.setOptionValue("parallel", "on");
    highs.setOptionValue("output_flag", "false");

    // do
    // {
        highs.run();
        const HighsInfo &info = highs.getInfo();
        const HighsSolution &highsSolution = highs.getSolution();

        // highs.changeColBounds(args); // dependend on highsSolution maybe repeatedly
    // } while (condition);

    HighsStatus return_status = highs.run();
    assert(return_status==HighsStatus::kOk);

    std::cout << highsStatusToString(return_status) << std::endl;

    return 0;
}