#include <QDebug>
#include "MyDataSource.h"

unsigned int MyDataSource::get_random_usage_value(const unsigned int uint_maximum_value,
                                                  const unsigned int uint_minimum_value)
    {
    const unsigned int uint_retval = (qrand() % (uint_maximum_value + 1));

    if (uint_retval < SOURCE_USAGE_MINIMUM)
        {
        return SOURCE_USAGE_MINIMUM;
        }

    else
        {
        return uint_retval;
        }
    }

void MyDataSource::get_hourly_day_usage_data(const unsigned int uint_hour,
                                             const QDate &qdate_selected_date,
                                             VectorOfUsageDataForOtherAndSpecificSources &vector_usage_data_destination)
    {
//    qDebug() << "Generating random data for the hour of " << uint_hour << " on the day of " << qdate_selected_date << "\n";

    // Clear the destination data vector

    vector_usage_data_destination.clear();
    vector_usage_data_destination.resize(5);

    // Add the random data value to the vector for the other source

    vector_usage_data_destination[SOURCE_OTHER] = get_random_usage_value(OTHER_SOURCE_USAGE_MAXIMUM);

    // Add the random data value to the vector for the 4 actual sources

    vector_usage_data_destination[SOURCE_1] = get_random_usage_value();
    vector_usage_data_destination[SOURCE_2] = get_random_usage_value();
    vector_usage_data_destination[SOURCE_3] = get_random_usage_value();
    vector_usage_data_destination[SOURCE_4] = get_random_usage_value();
    }

void MyDataSource::get_daily_month_usage_data(const unsigned int uint_date,
                                              const unsigned int uint_selected_month,
                                              const unsigned int uint_selected_year,
                                              VectorOfUsageDataForOtherAndSpecificSources &vector_usage_data_destination)
    {
//    qDebug() << "Generating random data for the date of " << uint_date << " on the month of " << uint_selected_month << " on the year of " << uint_selected_year << "\n";

    // Clear the destination data vector

    vector_usage_data_destination.clear();
    vector_usage_data_destination.resize(5);

    // Add the random data value to the vector for the other source (24 hrs worth of usage)

    vector_usage_data_destination[SOURCE_OTHER] = get_random_usage_value(OTHER_SOURCE_USAGE_MAXIMUM) * 24;

    // Add the random data value to the vector for the 4 actual sources (24 hrs worth of usage)

    vector_usage_data_destination[SOURCE_1] = get_random_usage_value() * 24;
    vector_usage_data_destination[SOURCE_2] = get_random_usage_value() * 24;
    vector_usage_data_destination[SOURCE_3] = get_random_usage_value() * 24;
    vector_usage_data_destination[SOURCE_4] = get_random_usage_value() * 24;
    }

void MyDataSource::get_monthly_year_usage_data(const unsigned int uint_month,
                                               const unsigned int uint_selected_month,
                                               const unsigned int uint_selected_year,
                                               VectorOfUsageDataForOtherAndSpecificSources &vector_usage_data_destination)
    {
//    qDebug() << "Generating random data for the month of " << uint_month << " starting from the month of " << uint_selected_month << " on the year of " << uint_selected_year << "\n";

    // Clear the destination data vector

    vector_usage_data_destination.clear();
    vector_usage_data_destination.resize(5);

    // Add the random data value to the vector for the other source (24 hrs worth of usage * 30 days)

    vector_usage_data_destination[SOURCE_OTHER] = get_random_usage_value(OTHER_SOURCE_USAGE_MAXIMUM) * 24 * 30;

    // Add the random data value to the vector for the 4 actual sources (24 hrs worth of usage * 30 days)

    vector_usage_data_destination[SOURCE_1] = get_random_usage_value() * 24 * 30;
    vector_usage_data_destination[SOURCE_2] = get_random_usage_value() * 24 * 30;
    vector_usage_data_destination[SOURCE_3] = get_random_usage_value() * 24 * 30;
    vector_usage_data_destination[SOURCE_4] = get_random_usage_value() * 24 * 30;
    }
