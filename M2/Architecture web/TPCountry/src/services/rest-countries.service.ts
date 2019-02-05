import { Country } from './../models/country';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import {HttpClient, HttpErrorResponse } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class RestCountriesService {

  private byCountryName = 'https://restcountries.eu/rest/v2/name/';
  private byRegionName = 'https://restcountries.eu/rest/v2/region/';
  private getOnlyNames = '?fields=name';
  private getUsedFields = '?fields=name;population;area;region;capital;currency;flag';

  constructor(private httpClient: HttpClient) { }

  public getByName(name: string): Observable<Country[]> {
    return this.httpClient.get<Country[]>(this.byCountryName + name + this.getUsedFields);
  }

  public getNamesByRegion(region: string): Observable<Country[]> {
    try {
      return this.httpClient.get<Country[]>(this.byRegionName + name + this.getOnlyNames);
    } catch (e) {
      console.error(e);
      return new Observable<Country[]>();
    }
  }
}
