# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:

from django.urls import path
from django.contrib import admin
from . import views

urlpatterns = [
    path('login', views.login, name = 'login'),
    path('register', views.register, name = 'register'),
    path('index', views.index, name = 'index'),
    path('', views.success, name = 'success'),
    path('star', views.star, name='star'),
    path('history', views.history, name='history'),
    path('show', views.show, name='show'),
    path("changePwd", views.changePwd, name='changePwd'),
    path("indexCompany", views.indexCompany, name='indexCompany'),
    path("profile", views.profile, name='profile'),
    path("logout", views.logout, name='logout'),
    path("deleteJob", views.deleteJob, name='deleteJob'),
    path("addJob", views.addJob, name='addJob'),
    path("changeJob", views.changeJob, name='changeJob'),
    # path("createRelation", views.createRelation, name='createRelation'),
    path("visualization", views.visualization, name='visualization'),
    path("findJob", views.findJob, name='findJob'),
    path("studentInfo", views.studentInfo, name='studentInfo')
]