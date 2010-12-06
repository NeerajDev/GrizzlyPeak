#include "CommonUtility.h"

//Method kept to generate new guid and return the same.
QString CommonUtility::getGUID()
{
        QString guid = QUuid::createUuid().toString();
        guid = guid.replace("{","");
        guid = guid.replace("}","");
        return guid;
}


CommonUtility::CommonUtility()
{

}

CommonUtility::CommonUtility(const CommonUtility &copy)
{

}

