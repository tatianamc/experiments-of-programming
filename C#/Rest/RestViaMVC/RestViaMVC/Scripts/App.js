'use strict';

var myApp = angular.module('myApp', [
  'controllersM'
]);

var controllersM = angular.module('controllersM', []);


controllersM.controller('MainCntl', function ($scope, $http) {

    //$scope.ticket = { "Id": 32, "Name": "wer", "Number": "qeeq" };

    $scope.init = function () {

        $http.get('http://localhost:58952/Home/All').
                  success(function (data, status, headers, config) {
                      $scope.tickets = data;
                  }).
                  error(function (data, status, headers, config) {
                      alert("error data load, will be used test data");
                  });
    };


    $scope.add = function (ticket) {

        $scope.tickets.push(ticket);
        /*$http.post('http://localhost:58952/Home/Create').
                  success(function (data, status, headers, config) {
                      $scope.tickets = data;
                  }).
                  error(function (data, status, headers, config) {
                      alert("error data load, will be used test data");
                  });*/
    };

    /*
    $scope.update = function () {

        $http.put('http://localhost:58952/Home/Update', $scope.place).
            success(function (data, status, headers, config) {
                //$scope.message = "Запись добавлена, можете добавить еще одну";
                $scope.place = undefined;
            });

    }*/


});