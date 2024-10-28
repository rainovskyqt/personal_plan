#ifndef EDUCATIONWORK_H
#define EDUCATIONWORK_H

#include <QMap>
#include <QObject>
#include "hours.h"

class EducationWork : public QObject
{
    Q_OBJECT
public:
    explicit EducationWork(QObject *parent = nullptr);

    int id() const;
    void setId(int newId);
    int disciplineId() const;
    void setDisciplineId(int newDisciplineId);
    int courseId() const;
    void setCourseId(int newCourseId);
    int workFormId() const;
    void setWorkFormId(int newWorkFormId);
    int groupCount() const;
    void setGroupCount(int newGroupCount);
    QString comments() const;
    void setComments(const QString &newComments);
    int orderPalce() const;
    void setOrderPalce(int newOrderPalce);
    void setHours(QString hoursStr);

    QMap<int, Hour *> hours() const;

signals:

private:
    int m_id;
    int m_disciplineId;
    int m_courseId;
    int m_workFormId;
    int m_groupCount;
    QString m_comments;
    int m_orderPalce;
    QMap<int, Hour*> m_hours;
};

#endif // EDUCATIONWORK_H
