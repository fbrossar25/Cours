import { TestBed } from '@angular/core/testing';

import { PrestationsService } from './prestations.service';

describe('PrestationsService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: PrestationsService = TestBed.get(PrestationsService);
    expect(service).toBeTruthy();
  });
});
