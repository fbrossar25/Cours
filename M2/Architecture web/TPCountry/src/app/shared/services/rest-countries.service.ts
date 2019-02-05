import { Country } from './../models/country';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import {HttpClient } from '@angular/common/http';
import { CountryShort } from './../models/country-short';

@Injectable({
  providedIn: 'root'
})
export class RestCountriesService {

  private API = 'https://restcountries.eu/rest/v2/';
  private getShort = '?fields=name;alpha3Code';
  private getUsedFields = '?fields=name;population;area;region;capital;currencies;flag';

  constructor(private httpClient: HttpClient) { }

  public getByName(name: string): Observable<Country[]> {
    return this.httpClient.get<Country[]>(`${this.API}name/${name}${this.getUsedFields}`);
  }

  public getNamesByRegion(region: string): Observable<CountryShort[]> {
    return this.httpClient.get<CountryShort[]>(`${this.API}region/${region}${this.getShort}`);
  }

  public getByAlphaCode(code: string): Observable<Country> {
    return this.httpClient.get<Country>(`${this.API}alpha/${code}${this.getUsedFields}`);
  }

  public getByProperty(property: string, value: string): Observable<Country[]> {
    return this.httpClient.get<Country[]>(`${this.API}${property}/${value}${this.getUsedFields}`);
  }

  public getNamesByProperty(property: string, value: string): Observable<CountryShort[]|CountryShort> {
    return this.httpClient.get<CountryShort[]|CountryShort>(`${this.API}${property}/${value}${this.getShort}`);
  }
}
