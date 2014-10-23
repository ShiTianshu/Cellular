#include "service.h"
#include "inputmethod.h"
#include "common.h"
#include "exceptions.h"
#include "isource.h"

Service::Service()
{
}

void Service::slotFind(const QString &sourceId, const QString &key, PCursor *ppCursor)
{
    // 获得当前的InputMethod
    InputMethod *pInputMethod = _pEnvironment->pCurrentInputMethod;
    if (!pInputMethod)
    {
        throw Exception("slotFind:当前输入法为空。");
    }
    ISource *pSource = pInputMethod->getSource(sourceId);
    if (!pSource)
    {
        throw SourceNotFoundException(QString("slotFind:没有找到ID为%1的数据源。").arg(sourceId));
    }
    ICursor *pICursor = pSource->query(key);
    if (!pICursor)
    {
        throw Exception(QString("slotFind:数据源%1查找%2未返回游标。").arg(pSource->idAndName()).arg(key));
    }
    *ppCursor = QSharedPointer< ICursor >(pICursor); 
}
