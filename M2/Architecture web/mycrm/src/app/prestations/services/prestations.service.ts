import { Injectable } from '@angular/core';
import { PrestationsCollection } from './../containers/fake-collection';
import { collectExternalReferences } from '@angular/compiler';
import { Prestation } from 'src/app/shared/model/prestation';

@Injectable({
  providedIn: 'root'
})
export class PrestationsService {
  private _collection: Prestation[] = PrestationsCollection;
  constructor() { }
  public getCollection () {
    return this._collection;
  }
  public setCollection(collection: Prestation[]) {
    this._collection = collection;
  }
  public add(prestation: Prestation) {
    this._collection.push(prestation);
  }
}
