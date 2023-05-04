from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn import metrics
import pickle

# train test split


def splitdata(df):

    train = df[['buying', 'maint', 'doors', 'persons', 'lug_boot', 'safety']]

    test = df['class']

    X_train, X_test, y_train, y_test = train_test_split(
        train, test, test_size=0.2)

    return X_train, X_test, y_train, y_test


# Logistic Regression

def logistic(df):

    X_train, X_test, y_train, y_test = splitdata(df)
    lr = LogisticRegression()
    lr.fit(X_train, y_train)
    y_pred = lr.predict(X_test)
    accuracy = metrics.accuracy_score(y_test, y_pred)
    recall = metrics.recall_score(y_test, y_pred, average='macro')
    precision = metrics.precision_score(y_test, y_pred, average='macro')
    f1score = metrics.f1_score(y_test, y_pred, average='macro')
    return accuracy, recall, precision, f1score, lr


# Decision Tree

def dtree(df):

    X_train, X_test, y_train, y_test = splitdata(df)
    dt = DecisionTreeClassifier()
    dt.fit(X_train, y_train)
    y_pred = dt.predict(X_test)
    accuracy = metrics.accuracy_score(y_test, y_pred)
    recall = metrics.recall_score(y_test, y_pred, average='macro')
    precision = metrics.precision_score(y_test, y_pred, average='macro')
    f1score = metrics.f1_score(y_test, y_pred, average='macro')
    return accuracy, recall, precision, f1score, dt


# Random Forest
def randomforest(df):
    X_train, X_test, y_train, y_test = splitdata(df)
    rf = RandomForestClassifier()
    rf.fit(X_train, y_train)
    y_pred = rf.predict(X_test)
    accuracy = metrics.accuracy_score(y_test, y_pred)
    recall = metrics.recall_score(y_test, y_pred, average='macro')
    precision = metrics.precision_score(y_test, y_pred, average='macro')
    f1score = metrics.f1_score(y_test, y_pred, average='macro')
    return accuracy, recall, precision, f1score, rf


# SVC

def svc(df):
    X_train, X_test, y_train, y_test = splitdata(df)
    sv = SVC()
    sv.fit(X_train, y_train)
    y_pred = sv.predict(X_test)
    accuracy = metrics.accuracy_score(y_test, y_pred)
    recall = metrics.recall_score(y_test, y_pred, average='macro')
    precision = metrics.precision_score(y_test, y_pred, average='macro')
    f1score = metrics.f1_score(y_test, y_pred, average='macro')
    return accuracy, recall, precision, f1score, sv


# KNN

def knn(df):
    X_train, X_test, y_train, y_test = splitdata(df)
    knn = KNeighborsClassifier()
    knn.fit(X_train, y_train)
    y_pred = knn.predict(X_test)
    accuracy = metrics.accuracy_score(y_test, y_pred)
    recall = metrics.recall_score(y_test, y_pred, average='macro')
    precision = metrics.precision_score(y_test, y_pred, average='macro')
    f1score = metrics.f1_score(y_test, y_pred, average='macro')
    return accuracy, recall, precision, f1score, knn
