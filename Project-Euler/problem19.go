// Problem 19
// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

package main

import "fmt"

func leap_year(year int) bool {
	if year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) {
		return true
	}
	return false
}

// how many first of the month are sunday
func how_many(year, first_week_day int) (int, int) {
	months := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	if leap_year(year) {
		months[1] += 1
	}
	sundays := 0
	for _, days_in_month := range(months) {
		if first_week_day == 0 {
			sundays += 1
		}
		first_week_day = (first_week_day + days_in_month) % 7
	}
	return sundays, first_week_day
}

func main() {
	first_week_day := 2  // 1 Jan 1901 was Tuesday
	sundays, sundays_in_year := 0, 0
	for i := 1901; i <= 2000; i++ {
		sundays_in_year, first_week_day = how_many(i, first_week_day)
		sundays += sundays_in_year
	}
	fmt.Println(sundays)
}