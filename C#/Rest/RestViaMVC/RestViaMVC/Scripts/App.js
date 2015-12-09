'use strict';

var myApp = angular.module('myApp', [
  'controllersM'
]);

var controllersM = angular.module('controllersM', []);


controllersM.controller('MainCntl', function ($scope, $http) {

    $scope.enableUpdateMode = function (ticket) {
        $scope.ticket = ticket;
        $scope.isEditing = true;
        $scope.isAdding = false;
        $scope.isViewMode = false;
    }

    $scope.enableViewMode = function () {
        $scope.ticket = undefined;
        $scope.isEditing = false;
        $scope.isAdding = false;
        $scope.isViewMode = true;
    }

    $scope.enableAddMode = function () {
        $scope.ticket = undefined;
        $scope.isEditing = false;
        $scope.isAdding = true;
        $scope.isViewMode = false;
    }

    $scope.init = function () {

        $scope.enableViewMode();

        $http.get('http://localhost:58952/Home/All').
                  success(function (data, status, headers, config) {
                      $scope.tickets = data;
                  }).
                  error(function (data, status, headers, config) {
                      alert("error data load, will be used test data");
                  });
    };

    $scope.details = function (ticket) {
        $scope.ticket = ticket;
    }



    $scope.add = function (ticket) {

        $http.post('http://localhost:58952/Home/Create', ticket).
                  success(function (data, status, headers, config) {
                      var copy = JSON.parse(JSON.stringify(ticket));
                      $scope.tickets.push(copy);
                      $scope.enableViewMode();
                  }).
                  error(function (data, status, headers, config) {
                      alert("error data load, will be used test data");
                      $scope.enableViewMode();
                  });
    };

    $scope.remove = function (ticket) {
        var strId = ticket.Id.toString();
        var url = 'http://localhost:58952/Home/Delete/' + strId;
        console.log(url);
        $http.delete(url).
                  success(function (data, status, headers, config) {
                      var index = $scope.tickets.indexOf(ticket);
                      $scope.tickets.splice(index, 1);
                  }).
                  error(function (data, status, headers, config) {
                      alert("delete error"+data);
                  });
    };

    
    $scope.update = function (ticket) {

        $http.put('http://localhost:58952/Home/Update', ticket).
                  success(function (data, status, headers, config) {
                      $scope.enableViewMode();
                  }).
                  error(function (data, status, headers, config) {
                      alert("error data load, will be used test data");
                      $scope.enableViewMode();
                  });
    };


    


});