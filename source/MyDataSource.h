#ifndef MY_DATA_SOURCE_H
#define MY_DATA_SOURCE_H

#include <QDate>
#include <vector>
#include "Constants.h"

typedef std::vector<unsigned int> VectorOfUsageDataForOtherAndSpecificSources;

class MyDataSource
    {
    public:

        // Gets the hourly usage data for the given hour on the selected date for the other source and all other
        // sources (whether defined or not) and puts this data into the given vector. The other source is always first,
        // followed by the actual sources.

        static void get_hourly_day_usage_data(const unsigned int uint_hour,         // Midnight is 0, 12:00 PM is 12, 11:00 PM is 23, etc...
                                              const QDate &qdate_selected_date,
                                              VectorOfUsageDataForOtherAndSpecificSources &vector_usage_data_destination);

        static void get_daily_month_usage_data(const unsigned int uint_date,
                                               const unsigned int uint_selected_month,
                                               const unsigned int uint_selected_year,
                                               VectorOfUsageDataForOtherAndSpecificSources &vector_usage_data_destination);

        static void get_monthly_year_usage_data(const unsigned int uint_month,
                                                const unsigned int uint_selected_month,
                                                const unsigned int uint_selected_year,
                                                VectorOfUsageDataForOtherAndSpecificSources &vector_usage_data_destination);

    public slots:

    protected:

    private slots:

    private:

        static unsigned int get_random_usage_value(const unsigned int uint_maximum_value = SOURCE_USAGE_MAXIMUM,
                                                   const unsigned int uint_minimum_value = SOURCE_USAGE_MINIMUM);
    };

#endif // MY_DATA_SOURCE_H
