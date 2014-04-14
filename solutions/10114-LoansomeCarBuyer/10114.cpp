#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

void depreciate(const int current_month,
                const double payment,
                double &car_value,
                double &loan_amount,
                int &payoff_month,
                const double depreciation_percent)
{
  if(payoff_month != -1) return;

  car_value *= (1.0 - depreciation_percent);
  loan_amount -= payment;

  DEBUG(printf("DEPRECIATE m = %d p = %f cv = %f la = %f  dep = %f\n", current_month, payment, car_value, loan_amount, depreciation_percent));

  if(loan_amount < car_value) 
  {
    payoff_month = current_month;
    DEBUG(printf("PAYOFF m = %d p = %d\n", current_month, payoff_month));
  }
}

int main()
{
  int term_months;
  int num_depreciations;
  double downpayment;
  double loan_value;

  while(scanf("%d %lf %lf %d\n", &term_months, &downpayment, &loan_value, &num_depreciations) == 4)
  {
    if(term_months < 0) break;

    double car_value = loan_value + downpayment;
    double monthly_payment = loan_value / (double) term_months;

    DEBUG(printf("START term_months = %d downpayment = %f car_value = %f num_depreciations = %d loan_value = %f\n", term_months, downpayment, car_value, num_depreciations, loan_value));

    int current_month = 0;
    
    int depreciation_month;
    double depreciation_percent;

    int payoff_month = -1;

    // There will always be month 0
    if(scanf("%d %lf\n", &depreciation_month, &depreciation_percent) == 2);

    depreciate(current_month, 0, car_value, loan_value, payoff_month, depreciation_percent);
    ++current_month;

    for(int i = 1; i < num_depreciations; ++i)
    {
      // Keep depreciating at the old rate until we hit the new month
      double new_depreciation_percent;

      if(scanf("%d %lf\n", &depreciation_month, &new_depreciation_percent) == 2);
      
      while(current_month < depreciation_month)
      {
        depreciate(current_month, monthly_payment, car_value, loan_value, payoff_month, depreciation_percent);
        ++current_month;
      }

      depreciation_percent = new_depreciation_percent;
    }

    // Depreciate until end of term
    while(current_month < term_months)
    {
      depreciate(current_month, monthly_payment, car_value, loan_value, payoff_month, depreciation_percent);
      ++current_month;
    }

    if(payoff_month == -1) payoff_month = term_months;

    printf("%d mont%s\n", payoff_month, (payoff_month == 1 ? "h" : "hs"));
  }

  return 0;
}
