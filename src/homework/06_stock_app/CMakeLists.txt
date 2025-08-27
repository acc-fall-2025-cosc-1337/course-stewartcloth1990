add_library(hw_06_stock_library "bond.h" "bond.cpp"
							  "cash.h" "cash.cpp"
							  "holding.h" "holding.cpp"
							  "investment.h" "investment.cpp"
								"mutual_fund.h" "mutual_fund.cpp"
								"portfolio.h" "portfolio.cpp"
								"holding.h" "holding.cpp"
								"cash.h" "cash.cpp"
								"stock.h" "stock.cpp")
add_executable(hw_06_stock_exe "main.cpp" "bond.cpp" "cash.cpp" "holding.cpp" "investment.cpp" "mutual_fund.cpp" "portfolio.cpp" "stock.cpp")